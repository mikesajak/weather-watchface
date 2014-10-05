#pragma once

#include "definitions.h"

typedef enum {
  MESSAGE_CUR_TEMP,
  MESSAGE_MIN_TEMP,
  MESSAGE_MAX_TEMP,
  MESSAGE_ICON,
  MESSAGE_DESCRIPTION,
  MESSAGE_CITY
} weather_message_type_t;
typedef struct { weather_message_type_t weather_message_type; } MessageType;

  
void send_cmd(int key, int value);

void translate_app_error_code(AppMessageResult app_msg_error, char* text_buffer, uint8_t max_len);

void make_date_str(char* dest, const struct tm *time, LOCALE locale);