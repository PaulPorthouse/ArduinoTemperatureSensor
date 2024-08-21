#ifndef Timer_h
#define Timer_h
#include "Arduino.h"
class Timer {
    protected:
        unsigned long startMilliseconds;
        unsigned long lastIntervalMilliseconds;
    public:
        Timer();
        void setup();
        unsigned long getIntervalMilliseconds();
        unsigned long getTotalMilliseconds();
        void createInterval();
};
#endif