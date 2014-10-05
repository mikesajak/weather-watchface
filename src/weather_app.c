#include <pebble.h>
#include "main_window.h"
#include "definitions.h"
#include "utils.h"
  
UpdateConfig weather_update_cfg = {
  .update_delay = 60 * 15 * 1000, // 15 minutes,
  .rerequest_delay = 30 * 1000 // 30 seconds
};

#define MAX_NUM_REREQUESTS 5
UpdateStatus weather_update_status = {
  .last_request_time = 0,
  .last_update_time = 0,
  .request_pending = false,
  .num_retries = 0
};

AppTimer *weather_update_timer = NULL;

NightSavingConfig night_saving_cfg = {
  .enabled = true,
  .saving_interval = {
    .start_hour = 0,
    .start_minute = 30,
    .end_hour = 8,
    .end_minute = 00  
  }
};

NightSavingState night_saving_state = {
  .active = false
};

bool is_inside_cyclic_interval(uint8_t start, uint8_t end, uint8_t cycle, uint8_t value, bool end_inclusive) {
  if (end < start) {
    end += cycle;
    value += cycle;
  }

  bool result = value >= start && (end_inclusive ? value <= end : value < end);
  return result;
}

bool is_inside_interval(DailyInterval *interval, struct tm *time) {
//   if (is_inside_cyclic_interval(interval->start_hour+1, interval->end_hour-1, 24, time->tm_hour, true)) {
//     if (is_inside_cyclic_interval(interval->start_minute, interval->end_minute, 60, time->tm_min, false)) {
  if ((time->tm_hour == interval->start_hour && time->tm_min >= interval->start_minute)
      || is_inside_cyclic_interval(interval->start_hour+1, interval->end_hour-1, 24, time->tm_hour, true)
      || (time->tm_hour == interval->end_hour && time->tm_min < interval->end_minute)) {
    return true;
  }
//   }
  return false;
}

bool is_in_night_saving_period(NightSavingConfig *cfg, struct tm *time) {
  return cfg->enabled && is_inside_interval(&cfg->saving_interval, time);
}  

// forward decl
void switch_night_saving_mode(struct tm *tick_time);

void handle_clock_tick(struct tm *tick_time, TimeUnits units_changed) {
  switch_night_saving_mode(tick_time);
  main_window_set_cur_time(tick_time, night_saving_state.active);
}

void switch_night_saving_mode(struct tm *tick_time) {
  bool expected_night_saving = is_in_night_saving_period(&night_saving_cfg, tick_time);
  if (night_saving_state.active != expected_night_saving) {
    night_saving_state.active = expected_night_saving;
//     layer_set_hidden(text_layer_get_layer(s_time_sec_textlayer), night_saving_state.active);
//     layer_set_hidden(bitmap_layer_get_layer(s_night_mode_bitmaplayer), !night_saving_state.active);
    main_window_set_night_saving_active(night_saving_state.active);
    tick_timer_service_unsubscribe();
    if (night_saving_state.active) {
      APP_LOG(APP_LOG_LEVEL_INFO, "Night saving mode enabled (%02d:%02d:%02d)", 
             (int) tick_time->tm_hour, (int) tick_time->tm_min, (int) tick_time->tm_sec);
      tick_timer_service_subscribe(MINUTE_UNIT, handle_clock_tick);
    } else {
      APP_LOG(APP_LOG_LEVEL_INFO, "Night saving mode disabled (%02d:%02d:%02d)", 
             (int) tick_time->tm_hour, (int) tick_time->tm_min, (int) tick_time->tm_sec);
      tick_timer_service_subscribe(SECOND_UNIT, handle_clock_tick);
    }
  }  
}

void request_weather_update(void *data) {
  time_t cur_time = time(NULL);
  struct tm *tick_time = localtime(&cur_time);
  APP_LOG(APP_LOG_LEVEL_DEBUG_VERBOSE, "Request weather update - timer handler (%02d:%02d:%02d)",
         (int) tick_time->tm_hour, (int) tick_time->tm_min, (int) tick_time->tm_sec);
  
  time_t compare_time = !weather_update_status.request_pending ?
                          weather_update_status.last_update_time : weather_update_status.last_request_time;

  weather_update_status.last_request_time = cur_time;
  if (!weather_update_status.request_pending) {
    weather_update_status.request_pending = true;
    APP_LOG(APP_LOG_LEVEL_INFO, "Requesting weather update (%02d:%02d:%02d)", 
            (int) tick_time->tm_hour, (int) tick_time->tm_min, (int) tick_time->tm_sec);
    
    send_cmd(1,1); // dummy command - send anything to trigger update
    
    // schedule rerequeest in case if HTTP request fails
    weather_update_timer = app_timer_register(weather_update_cfg.rerequest_delay, request_weather_update, NULL);
    
  } else {
    if (weather_update_status.num_retries >= MAX_NUM_REREQUESTS) {
      // abort re-requesting
      // switch to normal mode - and try again after regular request delay
      APP_LOG(APP_LOG_LEVEL_WARNING, "Max number re-requests reached (%0d:%0d:%0d), back off and try again after regular delay %ds", 
              (int) tick_time->tm_hour, (int) tick_time->tm_min, (int) tick_time->tm_sec,
              (int) weather_update_cfg.update_delay);
      
      weather_update_status.num_retries = 0;
      main_window_set_weather_retry_num(0);
      
      weather_update_status.request_pending = false;
//       weather_update_status.last_update_time = cur_time; // store last request time, to force regular delay from now
      
      // register next request with regular delay
      weather_update_timer = app_timer_register(weather_update_cfg.update_delay, request_weather_update, NULL);
    } else {
      APP_LOG(APP_LOG_LEVEL_INFO, "Re-requesting weather update, retry=%d, (%02d:%02d:%02d)", 
              (int) weather_update_status.num_retries,
              (int) tick_time->tm_hour, (int) tick_time->tm_min, (int) tick_time->tm_sec);
      weather_update_status.num_retries++;
      
      main_window_set_weather_retry_num(weather_update_status.num_retries);
      
      send_cmd(1,1); // dummy command - send anything to trigger update
      
      // register next request with shord re-request delay, in case if this HTTP request fails
      app_timer_register(weather_update_cfg.rerequest_delay, request_weather_update, NULL);
    }
  }
}

void update_weather_timestamp() {
  weather_update_status.request_pending = false;
    
  //Set time this update came in
//   static char time_buffer[] = "XX:XX:XX";
  weather_update_status.last_update_time = time(NULL);
  struct tm *tm = localtime(&weather_update_status.last_update_time);
//   strftime(time_buffer, sizeof(time_buffer), "%H:%M:%S", tm);
  APP_LOG(APP_LOG_LEVEL_INFO, "Weather update received %d:%02d:%02d, next request after %dms",
          (int) tm->tm_hour, (int) tm->tm_min, (int) tm->tm_sec, (int) weather_update_cfg.update_delay);
  // cut the seconds
//   int8_t idx = sizeof(time_buffer) - 1;
//   while (idx >= 0 && time_buffer[idx] != ':') idx--;
//   time_buffer[idx] = 0;
  
//   text_layer_set_text(s_weather_time_textlayer, time_buffer);
//   text_layer_set_text(s_weather_retry_textlayer, "");
  
          
  if (weather_update_timer != NULL) {
    app_timer_reschedule(weather_update_timer, weather_update_cfg.update_delay);
  } else {
    weather_update_timer = app_timer_register(weather_update_cfg.update_delay, request_weather_update, NULL);
  }
}
  
void handle_bluetooth_event(bool connected) {
  main_window_set_bluetooth_state(connected);
}

void handle_battery_event(BatteryChargeState charge) {
  main_window_set_battery_state(charge);
}
  
void handle_tuple_change(const Tuple *tuple) {
//   APP_LOG(APP_LOG_LEVEL_DEBUG, "Tuple change: %d", (int) tuple->key);
  
  switch(tuple->key) {
    case MESSAGE_CUR_TEMP:
      main_window_set_weather_cur_temp(tuple->value->cstring);
      break;
    
    case MESSAGE_ICON:
      main_window_set_weather_icon(tuple->value->int8);
      break;
    
    case MESSAGE_CITY:
      main_window_set_weather_city(tuple->value->cstring);
      break;
      
    case MESSAGE_DESCRIPTION:
      main_window_set_weather_description(tuple->value->cstring);
      break;
    
    case MESSAGE_MIN_TEMP:
      break;
    
    case MESSAGE_MAX_TEMP:
      break;

    default:
      APP_LOG(APP_LOG_LEVEL_WARNING, "Unknown tuple received: %d", (int) tuple->key);
  }
}
  
void in_received_handler(DictionaryIterator *received, void *context) {
  // incoming message received
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Message received");
  
  Tuple *tuple = dict_read_first(received);
  while(tuple) {
    handle_tuple_change(tuple);
    tuple = dict_read_next(received);
  }
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Message processing done.");

  update_weather_timestamp();
}

void sync_tuple_changed_callback(const uint32_t key, const Tuple* new_tuple, 
                                 const Tuple* old_tuple, void* context) {
  update_weather_timestamp();
  handle_tuple_change(new_tuple);
}

void sync_error_callback(DictionaryResult dict_error, AppMessageResult app_message_error, void* context) {
  char buffer[128];
  translate_app_error_code(app_message_error, buffer, 127);
  APP_LOG(APP_LOG_LEVEL_WARNING, "Sync error: dict error code=%d, app error code=%d: %s", (int) dict_error, (int) app_message_error, buffer);
}

void app_message_init(void) {
  app_message_open(256, 16);
  app_message_register_inbox_received(in_received_handler);
//   Tuplet initial_values[] = {
//     TupletInteger(MESSAGE_CUR_TEMP, (int8_t) 1),
//     TupletInteger(MESSAGE_MIN_TEMP, (int8_t) 1),
//     TupletInteger(MESSAGE_MAX_TEMP, (int8_t) 1),
//     TupletInteger(MESSAGE_ICON, (int8_t) 1),
//     TupletCString(MESSAGE_DESCRIPTION, ""),
//     TupletCString(MESSAGE_CITY, "Loading...")
//   };
  
//   app_sync_init(&sync, sync_buffer, sizeof(sync_buffer),
//                 initial_values, ARRAY_LENGTH(initial_values),
//                 sync_tuple_changed_callback, sync_error_callback, NULL);
}
 
  
void accel_tap_handler(AccelAxisType axis, int32_t direction) {
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Shake detected: axis=%d, direction=%d", (int) axis, (int) direction);
  main_window_notify_shake_detected();  
}
  
void init() { // initialization
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Initializing...");
  // subscribe to app messages
  APP_LOG(APP_LOG_LEVEL_DEBUG_VERBOSE, "Init phone-watch message handler");
  app_message_init();
  
  // subscribe to update every minute
  APP_LOG(APP_LOG_LEVEL_DEBUG_VERBOSE, "Subscribe to time ticks");
  tick_timer_service_subscribe(SECOND_UNIT, handle_clock_tick);
  
  // subscribe to bluetooth events
  APP_LOG(APP_LOG_LEVEL_DEBUG_VERBOSE, "Init bluetooth events handler");
  bluetooth_connection_service_subscribe(handle_bluetooth_event);
  
  // subscribe to battery events
  APP_LOG(APP_LOG_LEVEL_DEBUG_VERBOSE, "Init battery events handler");
  battery_state_service_subscribe(handle_battery_event);
  
  // subcribe to accel tap events
  APP_LOG(APP_LOG_LEVEL_DEBUG_VERBOSE, "Init accel tap events handler");
  accel_tap_service_subscribe(accel_tap_handler);
  
  // simulate first event
  APP_LOG(APP_LOG_LEVEL_DEBUG_VERBOSE, "Simulate first bluetooth event - to force refresh");
  handle_bluetooth_event(bluetooth_connection_service_peek());
  APP_LOG(APP_LOG_LEVEL_DEBUG_VERBOSE, "Simulate first battery event - to force refresh");
  handle_battery_event(battery_state_service_peek());
  APP_LOG(APP_LOG_LEVEL_DEBUG_VERBOSE, "Simulate first time tick - to force refresh");
  time_t cur_time = time(NULL);
  struct tm *tm = localtime(&weather_update_status.last_update_time);
  handle_clock_tick(tm, SECOND_UNIT);
  
  APP_LOG(APP_LOG_LEVEL_DEBUG_VERBOSE, "Request weather update right now");
  weather_update_timer = app_timer_register(3000, request_weather_update, NULL);

//   initialized = false;
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Initialization done.");
}

void deinit() { // deinitialization
  APP_LOG(APP_LOG_LEVEL_INFO, "Deinitializing...");
  tick_timer_service_unsubscribe();
  bluetooth_connection_service_unsubscribe();
  battery_state_service_unsubscribe();
  app_message_deregister_callbacks();
  accel_tap_service_unsubscribe();
  
//   if (NULL != shake_timer) {
//     app_timer_cancel(shake_timer);
//   }
  if (NULL != weather_update_timer) {
    app_timer_cancel(weather_update_timer);
  }
  
  APP_LOG(APP_LOG_LEVEL_DEBUG, "De-initialization done.");
}

int main(void) {
  show_main_window();
  init();
  app_event_loop();
  deinit();
}