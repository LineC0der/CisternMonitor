#ifndef SENSOR_HANDLER_H
#define SENSOR_HANDLER_H

#include <Arduino.h>
#include "config.h"
#include "lcdHandler.h"

class SensorHandler{
    public:
    int
        measureLevel(),
        calcVolume(int height);
};

#endif