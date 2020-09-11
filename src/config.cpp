#include "config.h"


// Network credentials
const char* WIFI_SSID = "SSID";
const char* WIFI_KEY = "PASSWORD";

//Miscellaneous
const char* HOSTNAME = "HOSTNAME";
const int BAUDRATE = 115200;
const int CISTERN_RADIUS = 100;
const int MONTAGE_HEIGHT = 200;
const int MIN_LEVEL = 10;
const int DIFF_MIN_MAX_CM = 180;
const String ue = "\365";
const int DIGITS_VOLUME = 4;
const int DIGITS_LEVEL = 3;

//LCD
const uint8_t LCD_ADR = 0x3F;
const uint8_t LCD_COLS = 20;
const uint8_t LCD_ROWS = 4;
const char BAR1[8] = {0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10};  // [|    ]
const char BAR2[8] = {0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18};  // [||   ]
const char BAR3[8] = {0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C};  // [|||  ]
const char BAR4[8] = {0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E};  // [|||| ]
const char BAR5[8] = {0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F};  // [|||||]
const int PB_WIDTH_BLOCKS = 18;                                         // |[..................]| 

//Timers
const int TIMER_BACKLIGHT_MS = 60000;
const int TIMER_USONIC_MS = 10000;

//OTA
const char* OTA_PASSWORD = "PASSWORT";

//MQTT
const char* MQTT_BROKER = "BROCKER_IP";
const int MQTT_PORT = 1883;
const char* MQTT_USER = "USERNAME";
const char* MQTT_PASSWORD = "MQTT_PASSWORD";
const char* TOPIC_LEVEL = "TOPIC_LEVEL";
const char* TOPIC_VOLUME = "TOPIC_VOLUME";

//Sensors
const int USONIC_PULSE = 11;
const int USONIC_PAUSE = 10;
const int USONIC_CNT = 3;

//Pins
const uint8_t PIN_MOTION_ECHO = D5;
const uint8_t PIN_USONIC_ECHO = D6;
const uint8_t PIN_USONIC_TRIG = D7;
