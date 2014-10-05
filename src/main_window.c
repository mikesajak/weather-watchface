#include <pebble.h>
#include <string.h>
#include "main_window.h"
#include "utils.h"
#include "definitions.h"

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
static GBitmap *s_res_image_shake_white;
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
static Layer *s_weather_layer;
static BitmapLayer *s_shake_bitmaplayer;
static InverterLayer *s_inverterlayer_1;

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
  s_res_image_shake_white = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_SHAKE_WHITE);
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
  
  // s_weather_layer
  s_weather_layer = layer_create(GRect(0, 70, 142, 96));
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_weather_layer);
  
  // s_shake_bitmaplayer
  s_shake_bitmaplayer = bitmap_layer_create(GRect(125, 22, 16, 16));
  bitmap_layer_set_bitmap(s_shake_bitmaplayer, s_res_image_shake_white);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_shake_bitmaplayer);
  
  // s_inverterlayer_1
  s_inverterlayer_1 = inverter_layer_create(GRect(0, 0, 144, 70));
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_inverterlayer_1);
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
  layer_destroy(s_weather_layer);
  bitmap_layer_destroy(s_shake_bitmaplayer);
  inverter_layer_destroy(s_inverterlayer_1);
  fonts_unload_custom_font(s_res_font_dolce_vita_48);
  gbitmap_destroy(s_res_image_battery_charge_white);
  gbitmap_destroy(s_res_image_bluetooth_white);
  gbitmap_destroy(s_res_image_night_mode_white);
  gbitmap_destroy(s_res_image_shake_white);
}
// END AUTO-GENERATED UI CODE

struct tm last_tick_time = {
  .tm_sec = 0, .tm_min = 0, .tm_hour = 0, .tm_mday = 0, .tm_mon = 0, .tm_year = 0
};

void main_window_set_cur_time(const struct tm *tick_time, bool is_night_saving) {
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
  
//   switch_night_saving_mode(tick_time);
//   if (!is_in_night_saving_period(&night_saving_cfg, tick_time)) {  
  if (!is_night_saving) {
    strftime(time_sec_text, 3, "%S", tick_time);
    text_layer_set_text(s_time_sec_textlayer, time_sec_text);
    
    last_tick_time.tm_sec = tick_time->tm_sec;
  }
  
//   request_weather_update_if_necessary(tick_time);
}

void main_window_set_night_saving_active(bool active) {
  layer_set_hidden(text_layer_get_layer(s_time_sec_textlayer), active);
  layer_set_hidden(bitmap_layer_get_layer(s_night_mode_bitmaplayer), !active);
}

void main_window_set_bluetooth_state(bool connected) {
  layer_set_hidden((Layer*) s_bluetooth_bitmaplayer, !connected);
}

void main_window_set_battery_state(BatteryChargeState charge) {
  static char bat_text[] = "100%";

  snprintf(bat_text, 5, "%0d%%", charge.charge_percent);
  
  text_layer_set_text(s_battery_textlayer, bat_text);
  layer_set_hidden((Layer *) s_battery_charge_bitmaplayer, !charge.is_plugged);
}

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

void main_window_set_weather_cur_temp(const char* temp_value) {
  static char temp_text[] = "100*C";
  strcpy(temp_text, temp_value);
  strcat(temp_text, "\u00B0");
  text_layer_set_text(s_weather_temp_textlayer, temp_text);
}

void main_window_set_weather_icon(int8_t id) {
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

void main_window_set_weather_city(const char* city) {
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

void main_window_set_weather_description(const char* descr) {
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
    while (descr[idx] == ' ' && descr[idx] != 0) idx++;
    strcpy(descr2_text, descr + idx);
  }
  
  text_layer_set_text(s_weather_descr1_textlayer, descr1_text);
  text_layer_set_text(s_weather_descr2_textlayer, descr2_text);
}

void main_window_update_weather_timestamp(time_t update_time) {
//   weather_update_status.request_pending = false;
  
  //Set time this update came in
  static char time_buffer[] = "XX:XX:XX";
//   weather_update_status.last_update_time = time(NULL);
  struct tm *tm = localtime(&update_time);
  strftime(time_buffer, sizeof(time_buffer), "%H:%M", tm);
//   APP_LOG(APP_LOG_LEVEL_INFO, "Weather update received %s, next request after %dms",
//           time_buffer, (int) weather_update_cfg.update_delay);
//   // cut the seconds
//   int8_t idx = sizeof(time_buffer) - 1;
//   while (idx >= 0 && time_buffer[idx] != ':') idx--;
//   time_buffer[idx] = 0;
  
  text_layer_set_text(s_weather_time_textlayer, time_buffer);
  text_layer_set_text(s_weather_retry_textlayer, "");
          
//   if (weather_update_timer != NULL) {
//     app_timer_reschedule(weather_update_timer, weather_update_cfg.update_delay);
//   } else {
//     weather_update_timer = app_timer_register(weather_update_cfg.update_delay, request_weather_update, NULL);
//   }
}

void main_window_set_weather_retry_num(const uint8_t retry) {
  static char retry_text[] = ".....";
  int i = 0;
  for (; i < retry; i++) {
    retry_text[i] = '.';
  }
  retry_text[i] = 0;
  text_layer_set_text(s_weather_retry_textlayer, retry_text);
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


AppTimer *shake_timer = NULL;
void hide_shake_bitmap_handler(void *data) {
  layer_set_hidden(bitmap_layer_get_layer(s_shake_bitmaplayer), true);
  shake_timer = NULL;
}

void main_window_notify_shake_detected() {
  layer_set_hidden(bitmap_layer_get_layer(s_shake_bitmaplayer), false);
  
  if (NULL == shake_timer) {
    shake_timer = app_timer_register(2000, hide_shake_bitmap_handler, NULL);
  } else {
    app_timer_reschedule(shake_timer, 2000);
  }
}


static void handle_window_unload(Window* window) {
  if (NULL != shake_timer) {
    app_timer_cancel(shake_timer);
  }
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
  layer_set_hidden(bitmap_layer_get_layer(s_shake_bitmaplayer), true);
  
  window_stack_push(s_window, true);
}

void hide_main_window(void) {
  window_stack_remove(s_window, true);
}


