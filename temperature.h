#ifndef Temperature_h
#define Temperature_h
#include "timer.h"
class Temperature {
protected:
  int thermistorPin;
  int tempReadIntervalMS;
  float temperature;
  Timer timer;
  void readTemperature();
public:
  Temperature(int thermistorPin, int tempReadIntervalMS);
  void setup();
  float getTemperature();
};
#endif