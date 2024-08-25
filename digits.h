#ifndef Digits_h
#define Digits_h
#include "Arduino.h"
#include "timer.h"
class Digits {
    protected:
        const byte digits[11] = {
            0x7E, 0x0C, 0xDA, 0x9E, 0xAC, 0xB6, 0xF6, 0x1C, 0xFE, 0xBC, 0x00
        };
        const int dataPins[8] = {
          2, 3, 4, 5, 6, 7, 8, 9
        };
        const int d1Pin = 12;
        const int d2Pin = 11;
        int digitDelay = 10;
        void displayDigit(int digit, int value);
        int values[2] = { 0, 0 };
        int dToDisplay = 0;
        Timer digitTimer = Timer();
        Timer displayTimer = Timer();
        int buttonDisplayDuration = 3000;

    public:
        Digits(int buttonDisplayDuration);
        void setup();
        void loop();
        void displayValue(int value);
        void clearDisplay();
};
#endif