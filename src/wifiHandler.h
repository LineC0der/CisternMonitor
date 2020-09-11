#ifndef WIFI_HANDLER_H
#define WIFI_HANDLER_H

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include "config.h"


class WifiHandler{
    public:
    void
        setupWifi();
};

#endif