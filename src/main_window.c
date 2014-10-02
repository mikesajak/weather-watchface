#include <pebble.h>
#include <string.h>
#include "main_window.h"
#include "my_calendar.h"
#include "messaging.h"

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GFont s_res_font_dolce_vita_48;
static GFont s_res_roboto_condensed_21;
static GFont s_res_gothic_18;
static GFont s_res_gothic_14;
static GBitmap *s_res_image_battery_charge_white;
static GBitmap *s_res_image_bluetooth_white;
static GFont s_res_bitham_42_light;
static GFont s_res_gothic_18_bold;
static GBitmap *s_res_image_night_mode_white;
static TextLayer *s_time_textlayer;
static TextLayer *s_time_sec_textlayer;
static TextLayer *s_date_textlayer;
static TextLayer *s_battery_textlayer;
static BitmapLayer *s_battery_charge_bitmaplayer;
static BitmapLayer *s_bluetooth_bitmaplayer;
static TextLayer *s_weather_temp_textlayer;
static BitmapLayer *s_weather_icon_bitmaplayer;
static TextLayer *s_weather_city_textlayer;
static TextLayer *s_weather_descr2_textlayer;
static TextLayer *s_weather_descr1_textlayer;
static TextLayer *s_weather_time_textlayer;
static TextLayer *s_weather_retry_textlayer;
static BitmapLayer *s_night_mode_bitmaplayer;
static InverterLayer *s_inverterlayer_1;
static Layer *s_weather_layer;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_background_color(s_window, GColorBlack);
  window_set_fullscreen(s_window, true);
  
  s_res_font_dolce_vita_48 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_DOLCE_VITA_48));
  s_res_roboto_condensed_21 = fonts_get_system_font(FONT_KEY_ROBOTO_CONDENSED_21);
  s_res_gothic_18 = fonts_get_system_font(FONT_KEY_GOTHIC_18);
  s_res_gothic_14 = fonts_get_system_font(FONT_KEY_GOTHIC_14);
  s_res_image_battery_charge_white = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BATTERY_CHARGE_WHITE);
  s_res_image_bluetooth_white = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BLUETOOTH_WHITE);
  s_res_bitham_42_light = fonts_get_system_font(FONT_KEY_BITHAM_42_LIGHT);
  s_res_gothic_18_bold = fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD);
  s_res_image_night_mode_white = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_NIGHT_MODE_WHITE);
  // s_time_textlayer
  s_time_textlayer = text_layer_create(GRect(0, 0, 102, 54));
  text_layer_set_background_color(s_time_textlayer, GColorBlack);
  text_layer_set_text_color(s_time_textlayer, GColorWhite);
  text_layer_set_text(s_time_textlayer, "23:59");
  text_layer_set_text_alignment(s_time_textlayer, GTextAlignmentRight);
  text_layer_set_font(s_time_textlayer, s_res_font_dolce_vita_48);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_time_textlayer);
  
  // s_time_sec_textlayer
  s_time_sec_textlayer = text_layer_create(GRect(108, 0, 36, 28));
  text_layer_set_background_color(s_time_sec_textlayer, GColorBlack);
  text_layer_set_text_color(s_time_sec_textlayer, GColorWhite);
  text_layer_set_text(s_time_sec_textlayer, "55");
  text_layer_set_font(s_time_sec_textlayer, s_res_roboto_condensed_21);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_time_sec_textlayer);
  
  // s_date_textlayer
  s_date_textlayer = text_layer_create(GRect(0, 48, 144, 22));
  text_layer_set_background_color(s_date_textlayer, GColorBlack);
  text_layer_set_text_color(s_date_textlayer, GColorWhite);
  text_layer_set_text(s_date_textlayer, "Sob 20 Październik");
  text_layer_set_text_alignment(s_date_textlayer, GTextAlignmentCenter);
  text_layer_set_font(s_date_textlayer, s_res_gothic_18);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_date_textlayer);
  
  // s_battery_textlayer
  s_battery_textlayer = text_layer_create(GRect(106, 34, 30, 20));
  text_layer_set_background_color(s_battery_textlayer, GColorBlack);
  text_layer_set_text_color(s_battery_textlayer, GColorWhite);
  text_layer_set_text(s_battery_textlayer, "99%");
  text_layer_set_text_alignment(s_battery_textlayer, GTextAlignmentRight);
  text_layer_set_font(s_battery_textlayer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_battery_textlayer);
  
  // s_battery_charge_bitmaplayer
  s_battery_charge_bitmaplayer = bitmap_layer_create(GRect(137, 34, 5, 18));
  bitmap_layer_set_bitmap(s_battery_charge_bitmaplayer, s_res_image_battery_charge_white);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_battery_charge_bitmaplayer);
  
  // s_bluetooth_bitmaplayer
  s_bluetooth_bitmaplayer = bitmap_layer_create(GRect(115, 24, 10, 11));
  bitmap_layer_set_bitmap(s_bluetooth_bitmaplayer, s_res_image_bluetooth_white);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_bluetooth_bitmaplayer);
  
  // s_weather_temp_textlayer
  s_weather_temp_textlayer = text_layer_create(GRect(0, 70, 72, 44));
  text_layer_set_background_color(s_weather_temp_textlayer, GColorBlack);
  text_layer_set_text_color(s_weather_temp_textlayer, GColorWhite);
  text_layer_set_text(s_weather_temp_textlayer, "15*");
  text_layer_set_text_alignment(s_weather_temp_textlayer, GTextAlignmentCenter);
  text_layer_set_font(s_weather_temp_textlayer, s_res_bitham_42_light);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_weather_temp_textlayer);
  
  // s_weather_icon_bitmaplayer
  s_weather_icon_bitmaplayer = bitmap_layer_create(GRect(73, 70, 72, 60));
  bitmap_layer_set_background_color(s_weather_icon_bitmaplayer, GColorBlack);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_weather_icon_bitmaplayer);
  
  // s_weather_city_textlayer
  s_weather_city_textlayer = text_layer_create(GRect(0, 150, 104, 18));
  text_layer_set_background_color(s_weather_city_textlayer, GColorBlack);
  text_layer_set_text_color(s_weather_city_textlayer, GColorWhite);
  text_layer_set_text(s_weather_city_textlayer, "Kraków");
  text_layer_set_font(s_weather_city_textlayer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_weather_city_textlayer);
  
  // s_weather_descr2_textlayer
  s_weather_descr2_textlayer = text_layer_create(GRect(0, 132, 144, 18));
  text_layer_set_background_color(s_weather_descr2_textlayer, GColorBlack);
  text_layer_set_text_color(s_weather_descr2_textlayer, GColorWhite);
  text_layer_set_text(s_weather_descr2_textlayer, "Mgła");
  text_layer_set_font(s_weather_descr2_textlayer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_weather_descr2_textlayer);
  
  // s_weather_descr1_textlayer
  s_weather_descr1_textlayer = text_layer_create(GRect(0, 117, 72, 18));
  text_layer_set_background_color(s_weather_descr1_textlayer, GColorBlack);
  text_layer_set_text_color(s_weather_descr1_textlayer, GColorWhite);
  text_layer_set_text(s_weather_descr1_textlayer, "Text layer");
  text_layer_set_font(s_weather_descr1_textlayer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_weather_descr1_textlayer);
  
  // s_weather_time_textlayer
  s_weather_time_textlayer = text_layer_create(GRect(102, 154, 42, 14));
  text_layer_set_background_color(s_weather_time_textlayer, GColorBlack);
  text_layer_set_text_color(s_weather_time_textlayer, GColorWhite);
  text_layer_set_text(s_weather_time_textlayer, "13:35");
  text_layer_set_text_alignment(s_weather_time_textlayer, GTextAlignmentRight);
  text_layer_set_font(s_weather_time_textlayer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_weather_time_textlayer);
  
  // s_weather_retry_textlayer
  s_weather_retry_textlayer = text_layer_create(GRect(118, 138, 26, 26));
  text_layer_set_background_color(s_weather_retry_textlayer, GColorClear);
  text_layer_set_text_color(s_weather_retry_textlayer, GColorWhite);
  text_layer_set_text(s_weather_retry_textlayer, ".....");
  text_layer_set_text_alignment(s_weather_retry_textlayer, GTextAlignmentRight);
  text_layer_set_font(s_weather_retry_textlayer, s_res_gothic_18_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_weather_retry_textlayer);
  
  // s_night_mode_bitmaplayer
  s_night_mode_bitmaplayer = bitmap_layer_create(GRect(112, 7, 16, 16));
  bitmap_layer_set_bitmap(s_night_mode_bitmaplayer, s_res_image_night_mode_white);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_night_mode_bitmaplayer);
  
  // s_inverterlayer_1
  s_inverterlayer_1 = inverter_layer_create(GRect(0, 0, 144, 70));
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_inverterlayer_1);
  
  // s_weather_layer
  s_weather_layer = layer_create(GRect(0, 70, 142, 96));
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_weather_layer);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  text_layer_destroy(s_time_textlayer);
  text_layer_destroy(s_time_sec_textlayer);
  text_layer_destroy(s_date_textlayer);
  text_layer_destroy(s_battery_textlayer);
  bitmap_layer_destroy(s_battery_charge_bitmaplayer);
  bitmap_layer_destroy(s_bluetooth_bitmaplayer);
  text_layer_destroy(s_weather_temp_textlayer);
  bitmap_layer_destroy(s_weather_icon_bitmaplayer);
  text_layer_destroy(s_weather_city_textlayer);
  text_layer_destroy(s_weather_descr2_textlayer);
  text_layer_destroy(s_weather_descr1_textlayer);
  text_layer_destroy(s_weather_time_textlayer);
  text_layer_destroy(s_weather_retry_textlayer);
  bitmap_layer_destroy(s_night_mode_bitmaplayer);
  inverter_layer_destroy(s_inverterlayer_1);
  layer_destroy(s_weather_layer);
  fonts_unload_custom_font(s_res_font_dolce_vita_48);
  gbitmap_destroy(s_res_image_battery_charge_white);
  gbitmap_destroy(s_res_image_bluetooth_white);
  gbitmap_destroy(s_res_image_night_mode_white);
}
// END AUTO-GENERATED UI CODE

struct tm last_tick_time = {
  .tm_sec = 0, .tm_min = 0, .tm_hour = 0, .tm_mday = 0, .tm_mon = 0, .tm_year = 0
};

typedef struct {
  time_t update_delay;
  time_t rerequest_delay;
} UpdateConfig;

typedef struct {
  time_t last_request_time;
  time_t last_update_time;
  bool request_pending;
  uint8_t num_retries;
} UpdateStatus;

typedef struct {
  uint8_t start_hour;
  uint8_t start_minute;
  uint8_t end_hour;
  uint8_t end_minute;
} DailyInterval;

typedef struct {
  bool night_saving_enabled;
  DailyInterval saving_interval;
  
} NightSavingConfig;

UpdateConfig weather_update_cfg = {
  .update_delay = 60 * 15, // 15 minutes,
  .rerequest_delay = 30 // seconds
};

#define MAX_NUM_REREQUESTS 5
UpdateStatus weather_update_status = {
  .last_request_time = 0,
  .last_update_time = 0,
  .request_pending = false,
  .num_retries = 0
};

NightSavingConfig night_saving_cfg = {
  .night_saving_enabled = true,
  .saving_interval = {
    .start_hour = 0,
    .start_minute = 30,
    .end_hour = 8,
    .end_minute = 00  
  }
};
bool night_saving_active = false;

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

bool is_night_saving_active(NightSavingConfig *cfg, struct tm *time) {
  return cfg->night_saving_enabled && is_inside_interval(&cfg->saving_interval, time);
}      

bool request_weather_update_if_necessary(struct tm *tick_time) {
  // check if weather update delay has passed
  time_t cur_time = time(NULL);
  time_t delay = !weather_update_status.request_pending ?
                    weather_update_cfg.update_delay : weather_update_cfg.rerequest_delay;
  time_t compare_time = !weather_update_status.request_pending ?
                          weather_update_status.last_update_time : weather_update_status.last_request_time;

  if (difftime(cur_time, compare_time) >= delay) {
    weather_update_status.last_request_time = cur_time;
    if (!weather_update_status.request_pending) {
      weather_update_status.request_pending = true;
      APP_LOG(APP_LOG_LEVEL_INFO, "Requesting weather update (%02d:%02d:%02d)", 
              (int) tick_time->tm_hour, (int) tick_time->tm_min, (int) tick_time->tm_sec);
    } else {
      if (weather_update_status.num_retries >= MAX_NUM_REREQUESTS) {
        // abort re-requesting
        // switch to normal mode - and try again after regular request delay
        APP_LOG(APP_LOG_LEVEL_WARNING, "Max number re-requests reached (%0d:%0d:%0d), back off and try again after regular delay %ds", 
                (int) tick_time->tm_hour, (int) tick_time->tm_min, (int) tick_time->tm_sec,
                (int) weather_update_cfg.update_delay);
        text_layer_set_text(s_weather_retry_textlayer, "");
        weather_update_status.num_retries = 0;
        weather_update_status.request_pending = false;
        weather_update_status.last_update_time = cur_time; // store last request time, to force regular delay from now
        return false;
      } else {
        APP_LOG(APP_LOG_LEVEL_INFO, "Re-requesting weather update, retry=%d, (%02d:%02d:%02d)", 
                (int) weather_update_status.num_retries,
                (int) tick_time->tm_hour, (int) tick_time->tm_min, (int) tick_time->tm_sec);
        weather_update_status.num_retries++;
        static char retry_text[] = ".....";
        int i = 0;
        for (; i < weather_update_status.num_retries; i++) {
          retry_text[i] = '.';
        }
        retry_text[i] = 0;
        text_layer_set_text(s_weather_retry_textlayer, retry_text);
      }
    }
    send_cmd(1,1); // dummy command - send anything to trigger update
    return true;
  }
  return false;
}

// forward declaration
void switch_night_saving_mode(struct tm *tick_time);

// show the date and time every minute
void handle_clock_tick(struct tm *tick_time, TimeUnits units_changed) {
  const LOCALE locale = PL;
  
  // Need to be static because they're used by the system later.
  static char time_text[] = "00:00";
  static char time_sec_text[] = "00";
  static char date_text[] = "Xxx, Xxxxxxxxxxx 00x";

  char *time_format;
  
  // update date only if needed
  if (tick_time->tm_mday != last_tick_time.tm_mday
     || tick_time->tm_mon != last_tick_time.tm_mon
     || tick_time->tm_year != last_tick_time.tm_year) {
    make_date_str(date_text, tick_time, locale);
    text_layer_set_text(s_date_textlayer, date_text);
    
    last_tick_time.tm_mday = tick_time->tm_mday;
    last_tick_time.tm_mon = tick_time->tm_mon;
    last_tick_time.tm_year = tick_time->tm_year;
  }
    
  // update minutes and hours only if needed
  if (tick_time->tm_min != last_tick_time.tm_min
      || tick_time->tm_hour != last_tick_time.tm_hour) {   
    if (clock_is_24h_style()) {
      time_format = "%H:%M";
    } else {
      time_format = "%I:%M";
    }
  
    strftime(time_text, sizeof(time_text), time_format, tick_time);
  
    if (!clock_is_24h_style() && (time_text[0] == '0')) {
      memmove(time_text, &time_text[1], sizeof(time_text) - 1);
    }
  
    text_layer_set_text(s_time_textlayer, time_text);
    
    last_tick_time.tm_min = tick_time->tm_min;
    last_tick_time.tm_hour = tick_time->tm_hour;
  }
  
  if (!is_night_saving_active(&night_saving_cfg, tick_time)) {  
    strftime(time_sec_text, 3, "%S", tick_time);
    text_layer_set_text(s_time_sec_textlayer, time_sec_text);
    
    last_tick_time.tm_sec = tick_time->tm_sec;
  }
  switch_night_saving_mode(tick_time);
  
  request_weather_update_if_necessary(tick_time);
}

void switch_night_saving_mode(struct tm *tick_time) {
  bool expected_night_saving = is_night_saving_active(&night_saving_cfg, tick_time);
  if (night_saving_active != expected_night_saving) {
    night_saving_active = expected_night_saving;
    layer_set_hidden(text_layer_get_layer(s_time_sec_textlayer), night_saving_active);
    layer_set_hidden(bitmap_layer_get_layer(s_night_mode_bitmaplayer), !night_saving_active);
    tick_timer_service_unsubscribe();
    if (night_saving_active) {
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

void handle_bluetooth_event(bool connected) {
  layer_set_hidden((Layer*) s_bluetooth_bitmaplayer, !connected);
}

void handle_battery_event(BatteryChargeState charge) {
  static char bat_text[] = "100%";

  snprintf(bat_text, 5, "%0d%%", charge.charge_percent);
  
  text_layer_set_text(s_battery_textlayer, bat_text);
  layer_set_hidden((Layer *) s_battery_charge_bitmaplayer, !charge.is_plugged);
}

typedef enum {
  MESSAGE_CUR_TEMP,
  MESSAGE_MIN_TEMP,
  MESSAGE_MAX_TEMP,
  MESSAGE_ICON,
  MESSAGE_DESCRIPTION,
  MESSAGE_CITY
} weather_message_type_t;
typedef struct { weather_message_type_t weather_message_type; } MessageType;

static GBitmap *weather_icon_image = NULL;

#define NUM_WEATHER_ICONS 12
const int WEATHER_ICON_RESOURCE_IDS[NUM_WEATHER_ICONS] = {
  RESOURCE_ID_IMAGE_CLEAR_DAY,
  RESOURCE_ID_IMAGE_CLEAR_NIGHT,
  RESOURCE_ID_IMAGE_CLOUDY,
  RESOURCE_ID_IMAGE_FOG,
  RESOURCE_ID_IMAGE_PARTLY_CLOUDY_DAY,
  RESOURCE_ID_IMAGE_PARTLY_CLOUDY_NIGHT,
  RESOURCE_ID_IMAGE_LIGHT_RAIN,
  RESOURCE_ID_IMAGE_HEAVY_RAIN,
  RESOURCE_ID_IMAGE_THUNDER,
  RESOURCE_ID_IMAGE_SLEET,
  RESOURCE_ID_IMAGE_SNOW,
  RESOURCE_ID_IMAGE_WIND
};

void update_weather_temperature(const char* temp_value) {
  static char temp_text[] = "100*C";
  strcpy(temp_text, temp_value);
  strcat(temp_text, "\u00B0");
  text_layer_set_text(s_weather_temp_textlayer, temp_text);
}

void update_weather_icon(const int8_t id) {
  if (weather_icon_image != NULL) {
    gbitmap_destroy(weather_icon_image);
    layer_remove_from_parent(bitmap_layer_get_layer(s_weather_icon_bitmaplayer));
    bitmap_layer_destroy(s_weather_icon_bitmaplayer);
  }

  Layer *window_layer = window_get_root_layer(s_window);

  int icon_resource_id = RESOURCE_ID_IMAGE_ERROR;
  if (id >= 0 && id < NUM_WEATHER_ICONS) {
    icon_resource_id = WEATHER_ICON_RESOURCE_IDS[id];
  }
  weather_icon_image = gbitmap_create_with_resource(icon_resource_id);
  s_weather_icon_bitmaplayer = bitmap_layer_create(GRect(73, 70, 72, 60));
  bitmap_layer_set_bitmap(s_weather_icon_bitmaplayer, weather_icon_image);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_weather_icon_bitmaplayer));
}

void update_weather_city(const char* city) {
  text_layer_set_text(s_weather_city_textlayer, city);
}

size_t strpos(const char* text, char c) {
  int pos = 0;
  bool found = false;
  while (text[pos] != 0 && !found) {
    if (text[pos] == c) {
      found = true;
    } else {
      pos++;
    }
  }
  return found ? pos : -1;
}

#define MAX(a,b) ((a) >= (b) ? a : b)
#define MIN(a,b) ((a) <  (b) ? a : b)
  
// char * replace_pl_chars(char * text) {
//   int pos = 0;
//   char ch;
//   while (text[pos] != 0) {
//     switch (text[pos]) {
//       case 'ą': ch = 'a'; break;
//       case 'Ą': ch = 'A'; break;
//       case 'ć': ch = 'c'; break;
//       case 'Ć': ch = 'C'; break;
//       case 'ł': ch = 'l'; break;
//       case 'Ł': ch = 'L'; break;
//       case 'ń': ch = 'n'; break;
//       case 'Ń': ch = 'N'; break;
//       case 'ó': ch = 'o'; break;
//       case 'Ó': ch = 'O'; break;
//       case 'ś': ch = 's'; break;
//       case 'Ś': ch = 'S'; break;
//       case 'ż': ch = 'z'; break;
//       case 'Ż': ch = 'Z'; break;
//       case 'ź': ch = 'z'; break;
//       case 'Ź': ch = 'Z'; break;
//       default: ch = text[pos];
//     }
//     text[pos] = ch;
//     pos++;
//   }
//   return text;
// }

void update_weather_description(const char* descr) {
  static char descr1_text[] = "ZachmurzenieAA";
  static char descr2_text[31];
//   char descr[256];
//   strncpy(descr, orig_descr, sizeof(descr));
//   descr[255] = 0;
//   replace_pl_chars(descr);
  
//   APP_LOG(APP_LOG_LEVEL_DEBUG, "update_weather_description: descr=%s", descr);
  
  size_t idx = strpos(descr, ' ');
//   APP_LOG(APP_LOG_LEVEL_DEBUG, "update_weather_description: idx=%d", (int) idx);
  if (idx == (size_t)-1 || idx >= sizeof(descr1_text)) {
    strcpy(descr1_text, "");
    strcpy(descr2_text, descr);
  } else {
    size_t size = MIN(idx, sizeof(descr1_text) - 1);
//     APP_LOG(APP_LOG_LEVEL_DEBUG, "update_weather_description: size=%d/%d", (int) size, sizeof(descr1_text));
    strncpy(descr1_text, descr, size);
    descr1_text[size] = 0;
    while (descr[idx] == ' ' && descr[idx] != 0)
      idx++;
    strcpy(descr2_text, descr + idx);
  }
  
  text_layer_set_text(s_weather_descr1_textlayer, descr1_text);
  text_layer_set_text(s_weather_descr2_textlayer, descr2_text);
}

void update_weather_timestamp() {
//   if (!weather_request_pending) {
//     return;
//   }
  
  weather_update_status.request_pending = false;
  
  //Set time this update came in
  static char time_buffer[] = "XX:XX:XX";
  weather_update_status.last_update_time = time(NULL);
  struct tm *tm = localtime(&weather_update_status.last_update_time);
  strftime(time_buffer, sizeof(time_buffer), "%H:%M", tm);
  text_layer_set_text(s_weather_time_textlayer, time_buffer);
  text_layer_set_text(s_weather_retry_textlayer, "");
  
  APP_LOG(APP_LOG_LEVEL_INFO, "Weather update received %s, next request after %ds",
          time_buffer, (int) weather_update_cfg.update_delay);
}

void handle_tuple_change(const Tuple *tuple) {
//   APP_LOG(APP_LOG_LEVEL_DEBUG, "Tuple change: %d", (int) tuple->key);
  
  switch(tuple->key) {
    case MESSAGE_CUR_TEMP:
      update_weather_temperature(tuple->value->cstring);
      break;
    
    case MESSAGE_ICON:
      update_weather_icon(tuple->value->int8);
      break;
    
    case MESSAGE_CITY:
      update_weather_city(tuple->value->cstring);
      break;
      
    case MESSAGE_DESCRIPTION:
      update_weather_description(tuple->value->cstring);
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

PropertyAnimation *weather_layer_prop_animation;
bool animation_pending = false;
bool weather_layer_visible = true;

void animation_started(Animation *animation, void *data) {
  
}

void animation_stopped(Animation *animation, bool finished, void *data) {
  
}


void destroy_property_animation(PropertyAnimation **prop_anim) {
  if (*prop_anim == NULL) {
    return;
  }
}

void accel_tap_handler(AccelAxisType axis, int32_t direction) {
//   property_animation
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Shake detected: axis=%d, direction=%d", (int) axis, (int) direction);
}

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_main_window(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  
  // reattach weather related layers to single parent layer
  // this is required because cloud-pebble window layer editor does not support custom layer hierarchies
//   layer_add_child(s_weather_layer, text_layer_get_layer(s_weather_temp_textlayer));
//   layer_add_child(s_weather_layer, text_layer_get_layer(s_weather_descr1_textlayer));
//   layer_add_child(s_weather_layer, text_layer_get_layer(s_weather_descr2_textlayer));
//   layer_add_child(s_weather_layer, text_layer_get_layer(s_weather_time_textlayer));
//   layer_add_child(s_weather_layer, text_layer_get_layer(s_weather_city_textlayer));
//   layer_add_child(s_weather_layer, text_layer_get_layer(s_weather_retry_textlayer));
  
  // clear all layers - show proper init screen
  text_layer_set_text(s_time_textlayer, "");
  text_layer_set_text(s_time_sec_textlayer, "");
  text_layer_set_text(s_date_textlayer, "");
  
  text_layer_set_text(s_weather_temp_textlayer, "");
  text_layer_set_text(s_weather_descr1_textlayer, "");
  text_layer_set_text(s_weather_descr2_textlayer, "");
  text_layer_set_text(s_weather_time_textlayer, "");
  text_layer_set_text(s_weather_city_textlayer, "Loading...");
  text_layer_set_text(s_weather_retry_textlayer, "");
  
  layer_set_hidden(bitmap_layer_get_layer(s_night_mode_bitmaplayer), true);
  
  window_stack_push(s_window, true);
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
  APP_LOG(APP_LOG_LEVEL_DEBUG, "De-initialization done.");
}

void hide_main_window(void) {
  window_stack_remove(s_window, true);
}

int main(void) {
  show_main_window();
  init();
  app_event_loop();
  deinit();
}
