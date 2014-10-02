#pragma once

void send_cmd(int key, int value);

void translate_app_error_code(AppMessageResult app_msg_error, char* text_buffer, uint8_t max_len);
