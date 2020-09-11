#include "wifiHandler.h"


void WifiHandler::setupWifi(){
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_KEY);
    while (WiFi.waitForConnectResult() != WL_CONNECTED) {
        delay(2000);
        ESP.restart();
    }
}
