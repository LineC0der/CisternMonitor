#ifndef LCD_HANDLER_H
#define LCD_HANDLER_H

#include <LiquidCrystal_I2C.h>
#include "config.h"

class LcdHandler{
    private:
        LiquidCrystal_I2C* lcd;
    public:
        LcdHandler();
    void
        setupLcd(),
        resetText(),
        printOffset(int value, int maxWidth),
        progressBar(int level),
        printValues(int volume, int level),
        off(),
        on();
};

#endif
