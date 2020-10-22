#include "config.h"


// Network credentials
const char* WIFI_SSID = "SSID";
const char* WIFI_KEY = "PASSWORD";

//Miscellaneous
const char* HOSTNAME = "HOSTNAME";  //Hostname used for OTA-Updated
const int BAUDRATE = 115200;
const int CISTERN_RADIUS = 100;			//Radius of the Cistern
const int MONTAGE_HEIGHT = 200;			//Height of the HC-SR-04-Sensor
const int MIN_LEVEL = 10;           //Level on which to start the progress bar
const int DIFF_MIN_MAX_CM = 180;		//Height which will be visualized from the progress bar
const int DIGITS_VOLUME = 4;        //max. Digits needed for the Volume e.g. 6500l
const int DIGITS_LEVEL = 3;	        // -- || -- for level e.g. 175cm

//LCD
const uint8_t LCD_ADR = 0x3F;			  //I2C-Adress of the LCD (may be differnt)
const uint8_t LCD_COLS = 20;
const uint8_t LCD_ROWS = 4;
const char BAR1[8] = {0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10};  // [|    ]
const char BAR2[8] = {0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18};  // [||   ]
const char BAR3[8] = {0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C};  // [|||  ]
const char BAR4[8] = {0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E};  // [|||| ]
const char BAR5[8] = {0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F};  // [|||||]
const int PB_WIDTH_BLOCKS = 18;                                         // |[..................]|

//Timers
const int TIMER_BACKLIGHT_MS = 60000;	//backlight duration when turned on
const int TIMER_USONIC_MS = 10000;		//do a measurments every 10s

//OTA
const char* OTA_PASSWORD = "PASSWORD";

//MQTT
const char* MQTT_BROKER = "BROCKER_IP";
const int MQTT_PORT = 1883;
const char* MQTT_USER = "USERNAME";
const char* MQTT_PASSWORD = "MQTT_PASSWORD";
const char* TOPIC_LEVEL = "TOPIC_LEVEL";
const char* TOPIC_VOLUME = "TOPIC_VOLUME";

//Sensors
const int USONIC_PULSE = 11;		//pulse duration for HC-SR-04 11ms
const int USONIC_PAUSE = 10;		//wait 10ms before next pulse
const int USONIC_CNT = 3;			  //max. 3 pulses in a row

//Pins
const uint8_t PIN_MOTION_ECHO = D5;
const uint8_t PIN_USONIC_ECHO = D6;
const uint8_t PIN_USONIC_TRIG = D7;
