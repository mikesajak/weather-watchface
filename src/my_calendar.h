#pragma once

const char* MONTH_NAMES_EN[] = {
  "January",
  "February",
  "March",
  "April",
  "May",
  "June",
  "July",
  "August",
  "September",
  "October",
  "November",
  "December"
};

const char* MONTH_NAMES_PL[] = {
  "Styczen",
  "Luty",
  "Marzec",
  "Kwiecien",
  "Maj",
  "Czerwiec",
  "Lipiec",
  "Sierpien",
  "Wrzesien",
  "Pazdziernik",
  "Listopad",
  "Grudzien"
};

const char** MONTH_NAMES[] = {
  MONTH_NAMES_EN,
  MONTH_NAMES_PL
};

const char* WEEKDAY_NAMES_EN[] = {
  "Sun", "Mon", "Tue", "Wed", "Thu", "Sat"
};
const char* WEEKDAY_NAMES_PL[] = {
  "Nie", "Pon", "Wt", "Sr", "Czw", "Pt", "Sob"
};

const char** WEEKDAY_NAMES[] = {
  WEEKDAY_NAMES_EN,
  WEEKDAY_NAMES_PL
};

typedef enum {
  EN = 0,
  PL
} LOCALE;


void make_date_str(char* dest, struct tm *time, LOCALE locale) {
  strcpy(dest, WEEKDAY_NAMES[locale][time->tm_wday]);
  strcat(dest, ", ");
  strftime(&dest[strlen(dest)], 4, "%e ", time);
  strcat(dest, MONTH_NAMES[locale][time->tm_mon]);
}
