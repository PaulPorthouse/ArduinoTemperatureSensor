#ifndef Brightness_pot_h
#define Brightness_pot_h
#include "timer.h"
class AnalogReader {
  protected:
    int analogPin;
    int readIntervalMS;
    int value;
    Timer timer;
    int readValue();
  public:
    AnalogReader(int analogPin, int tempReadIntervalMS);
    void setup();
    int getValue();
    float getNormalisedValue();
};
#endif