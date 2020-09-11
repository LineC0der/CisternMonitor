#include "sensorHandler.h"


int SensorHandler::measureLevel(){
    int distance = 0, prev = 0;
    unsigned long duration = 0;
    digitalWrite(LED_BUILTIN, LOW);
    for(int i = 0; i < USONIC_CNT; i++) {
        yield();                     
        digitalWrite(PIN_USONIC_TRIG, HIGH);
        delayMicroseconds(USONIC_PULSE);
        digitalWrite(PIN_USONIC_TRIG, LOW);
        duration = pulseIn(PIN_USONIC_ECHO, HIGH, 15000);      //Timeout after 15000us ~ 2,5m distance
        if (duration > 0) {
            distance = 0.0343 * (duration / 2.0);
        }
        if(duration == 0 || distance > MONTAGE_HEIGHT) {
            distance = MONTAGE_HEIGHT;
        }
        if(distance != prev) {
            prev = distance;
            i = 0;
        }
        delay(USONIC_PAUSE);
    }
    digitalWrite(LED_BUILTIN, HIGH);
    return (MONTAGE_HEIGHT - distance);
}

int SensorHandler::calcVolume(int level) {
    return (PI * sqrt(CISTERN_RADIUS) * (level));
}
