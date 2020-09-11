#include "otaHandler.h"


void OtaHandler::setupOta(){
    ArduinoOTA.setHostname(HOSTNAME);
    ArduinoOTA.setPassword(OTA_PASSWORD);
    ArduinoOTA.onStart([](){});
    ArduinoOTA.begin();
    ArduinoOTA.onProgress({});
    ArduinoOTA.onEnd([](){});
    ArduinoOTA.onError({});
}

void OtaHandler::handleOta(){
    ArduinoOTA.handle();
}
