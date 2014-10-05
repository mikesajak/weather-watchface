#pragma once
  
#include <pebble.h>

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
  bool enabled;
  DailyInterval saving_interval;
} NightSavingConfig;

typedef struct {
  bool active;
} NightSavingState;
  

// extern const char* MONTH_NAMES_EN[];

// extern const char* MONTH_NAMES_PL[];

extern const char** MONTH_NAMES[];

// extern const char* WEEKDAY_NAMES_EN[];
// extern const char* WEEKDAY_NAMES_PL[];

extern const char** WEEKDAY_NAMES[];

typedef enum {
  EN = 0,
  PL
} LOCALE;