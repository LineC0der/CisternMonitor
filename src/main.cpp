#include <Arduino.h>
#include <os_type.h>
#include "wifiHandler.h"
#include "otaHandler.h"
#include "mqttHandler.h"
#include "lcdHandler.h"
#include "sensorHandler.h"

//Handler-Objects
WifiHandler wifi;
OtaHandler ota;
MqttHandler mqtt;
LcdHandler lcd;
SensorHandler sensors;

//Timer-Objects
os_timer_t lcdTimer;
os_timer_t usonicTimer;

//Interrupt-Control-Values
bool usonicTimerTicked = true;    // do a measurement on startup
bool lcdTimerTicked = false;      // lcd won't be turned off on startup
bool motionDetected = false;      // start with lcd on

//Global-Prev-Variables
int prevLevel = 0;
int prevVolume = 0;

void usonicTimerAction(void* pArg) {
  usonicTimerTicked = true;
}

void lcdTimerAction(void* pArg) {
  lcdTimerTicked = true;
}

void ICACHE_RAM_ATTR motionSensorAction() {
  motionDetected = true;
}

void setupTimings() {
  os_timer_setfn(&usonicTimer, usonicTimerAction, NULL);
  os_timer_arm(&usonicTimer, TIMER_USONIC_MS, true);
  os_timer_setfn(&lcdTimer, lcdTimerAction, NULL);
  os_timer_arm(&lcdTimer, TIMER_BACKLIGHT_MS, false);
  attachInterrupt(digitalPinToInterrupt(PIN_MOTION_ECHO), motionSensorAction, RISING);
}

void doWaterMeasurement() {
  int level = 0, volume = 0;
  level = sensors.measureLevel();
  volume = sensors.calcVolume(level);
  if(level != prevLevel || volume != prevLevel) {
    lcd.printValues(volume, level);
    mqtt.sendValues(volume, level);
    prevLevel = level;
    prevVolume = volume;
  }
}


void setup() {
  //Serial.begin(BAUDRATE);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PIN_USONIC_TRIG, OUTPUT);
  pinMode(PIN_USONIC_ECHO, INPUT);
  pinMode(PIN_MOTION_ECHO, INPUT);
  wifi.setupWifi();
  ota.setupOta();
  mqtt.setupMqtt();
  lcd.setupLcd();
  setupTimings();
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  ota.handleOta();
  mqtt.loopClient();
  if(lcdTimerTicked) {
    lcd.off();
    lcdTimerTicked = false;
  }
  if(motionDetected) {
    lcd.on();
    os_timer_arm(&lcdTimer, TIMER_BACKLIGHT_MS, false);
    motionDetected = false;
  }
  if(usonicTimerTicked) {
    doWaterMeasurement();
    usonicTimerTicked = false;
  }
}
