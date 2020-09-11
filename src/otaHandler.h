#ifndef OTA_HANDLER_H
#define OTA_HANDLER_H

#include <ArduinoOTA.h>
#include "config.h"


class OtaHandler{
    public: 
    void
        setupOta(),
        handleOta();
};

#endif
