#include "lcdHandler.h"


LcdHandler::LcdHandler() {
    lcd = new LiquidCrystal_I2C(LCD_ADR, LCD_COLS, LCD_ROWS);
}

void LcdHandler::setupLcd() {
    lcd->begin(LCD_COLS, LCD_ROWS);
    lcd->init();
    lcd->createChar(1, BAR1);
    lcd->createChar(2, BAR2);
    lcd->createChar(3, BAR3);
    lcd->createChar(4, BAR4);
    lcd->createChar(5, BAR5);
    resetText();
    on();
}

void LcdHandler::resetText() {
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print(">  Cisternmonitor  <");
    lcd->setCursor(0, 1);
    lcd->print("Level:");
    lcd->setCursor(0, 2);
    lcd->print("Height:");
}

void LcdHandler::printOffset(int value, int cntDigits) {
    int digits = 1;
    for(int i = value; i >= 10; i /= 10) {
        ++digits;
    }
    for(int i = (cntDigits - digits); i > 0; i--) {
        lcd->print(" ");
    }
}

void LcdHandler::progressBar(int level) {
    int cmPerBlock = DIFF_MIN_MAX_CM / PB_WIDTH_BLOCKS;
    int cmPerPx = cmPerBlock / 5;
    lcd->setCursor(0, 3);
    lcd->print("[");
    if(level > MIN_LEVEL) {
        level -= MIN_LEVEL;
        while(level >= cmPerBlock) {
            lcd->write(5);
            level -= cmPerBlock;
        }
        if(level >= cmPerPx) {
            level /= cmPerPx;
            lcd->write(uint8_t(level));
        }
    }
    lcd->setCursor(19, 3);
    lcd->print("]");
}

void LcdHandler::printValues(int volume, int level) {
    resetText();
    lcd->setCursor(11, 1);
    printOffset(volume, DIGITS_VOLUME);
    lcd->print(String(volume) + " ltr");
    lcd->setCursor(12, 2);
    printOffset(level, DIGITS_LEVEL);
    lcd->print(String(level) + " cm");
    progressBar(level);
}

void LcdHandler::off() {
    lcd->noBacklight();
    lcd->noDisplay();
}

void LcdHandler::on() {
    lcd->display();
    lcd->backlight();
}
