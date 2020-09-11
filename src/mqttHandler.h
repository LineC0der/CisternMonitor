#ifndef MQTT_HANDLER_H
#define MQTT_HANDLER_H

#include <PubSubClient.h>
#include <ESP8266WiFi.h>
#include <Arduino.h>
#include "config.h"

class MqttHandler {
    public:
    void
        setupMqtt(),
        connectToBroker(),
        sendValues(int volume, int level),
        loopClient();
};

#endif
