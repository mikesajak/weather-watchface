#include <pebble.h>

void send_cmd(int key, int val) {
  Tuplet value = TupletInteger(key, val);
  DictionaryIterator *iter;
  app_message_outbox_begin(&iter);
  if (iter == NULL) {
    return;
  }
  dict_write_tuplet(iter, &value);
  dict_write_end(iter);
  app_message_outbox_send();
}

void translate_app_error_code(AppMessageResult app_msg_error, char* text_buffer, uint8_t max_len) {
  switch(app_msg_error) {
    case APP_MSG_OK:           strncpy(text_buffer, "APP_MSG_OK", max_len); break;
    case APP_MSG_SEND_TIMEOUT: strncpy(text_buffer, "APP_MSG_SEND_TIMEOUT", max_len); break;
    case APP_MSG_SEND_REJECTED: strncpy(text_buffer, "APP_MSG_SEND_REJECTED", max_len); break;
    case APP_MSG_NOT_CONNECTED: strncpy(text_buffer, "APP_MSG_NOT_CONNECTED", max_len); break;
    case APP_MSG_APP_NOT_RUNNING: strncpy(text_buffer, "APP_MSG_APP_NOT_RUNNING", max_len); break;
    case APP_MSG_INVALID_ARGS: strncpy(text_buffer, "APP_MSG_INVALID_ARGS", max_len); break;
    case APP_MSG_BUSY: strncpy(text_buffer, "APP_MSG_BUSY", max_len); break;
    case APP_MSG_BUFFER_OVERFLOW: strncpy(text_buffer, "APP_MSG_BUFFER_OVERFLOW", max_len); break;
    case APP_MSG_ALREADY_RELEASED: strncpy(text_buffer, "APP_MSG_ALREADY_RELEASED", max_len); break;
    case APP_MSG_CALLBACK_ALREADY_REGISTERED: strncpy(text_buffer, "APP_MSG_CALLBACK_ALREADY_REGISTERED", max_len); break;
    case APP_MSG_CALLBACK_NOT_REGISTERED: strncpy(text_buffer, "APP_MSG_CALLBACK_NOT_REGISTERED", max_len); break;
    case APP_MSG_OUT_OF_MEMORY: strncpy(text_buffer, "APP_MSG_OUT_OF_MEMORY", max_len); break;
    case APP_MSG_CLOSED: strncpy(text_buffer, "APP_MSG_CLOSED", max_len); break;
    case APP_MSG_INTERNAL_ERROR: strncpy(text_buffer, "APP_MSG_INTERNAL_ERROR", max_len); break;
    default: strncpy(text_buffer, "UNKNOWN", max_len); break;
  }
}
