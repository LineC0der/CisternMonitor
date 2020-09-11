#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// Network credentials
extern const char* WIFI_SSID;
extern const char* WIFI_KEY;

//Miscellaneous
extern const char* HOSTNAME;
extern const int BAUDRATE;
extern const int CISTERN_RADIUS;
extern const int MONTAGE_HEIGHT;
extern const int MIN_LEVEL;
extern const int DIFF_MIN_MAX_CM;
extern const String ue;
extern const int DIGITS_VOLUME;
extern const int DIGITS_LEVEL;

//LCD
extern const uint8_t LCD_ADR;
extern const uint8_t LCD_COLS;
extern const uint8_t LCD_ROWS;
extern const char BAR1[8];
extern const char BAR2[8];
extern const char BAR3[8];
extern const char BAR4[8];
extern const char BAR5[8];
extern const int PB_WIDTH_BLOCKS;

//Timers
extern const int TIMER_BACKLIGHT_MS;
extern const int TIMER_USONIC_MS;

//OTA
extern const char* OTA_PASSWORD;

//MQTT
extern const char* MQTT_BROKER;
extern const int MQTT_PORT;
extern const char* MQTT_USER;
extern const char* MQTT_PASSWORD;
extern const char* TOPIC_LEVEL;
extern const char* TOPIC_VOLUME;

//Sensors
extern const int USONIC_PULSE;
extern const int USONIC_PAUSE;
extern const int USONIC_CNT;

//Pins
extern const uint8_t PIN_MOTION_ECHO;
extern const uint8_t PIN_USONIC_ECHO;
extern const uint8_t PIN_USONIC_TRIG;
#endif