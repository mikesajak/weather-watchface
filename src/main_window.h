void show_main_window(void);
void hide_main_window(void);

void main_window_set_bluetooth_state(bool connected);
void main_window_set_battery_state(BatteryChargeState charge);

void main_window_set_cur_time(const struct tm *tick_time, bool is_night_saving);
void main_window_set_night_saving_active(bool active);

void main_window_set_weather_cur_temp(const char *temp_text);
void main_window_set_weather_icon(int8_t icon_idx);
void main_window_set_weather_city(const char *city_text);
void main_window_set_weather_description(const char *description);
void main_window_update_weather_timestamp(time_t update_time);
void main_window_set_weather_retry_num(uint8_t retry);

void main_window_notify_shake_detected();

