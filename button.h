#ifndef Button_h
#define Button_h
#include "Arduino.h"
class Button {
    protected:
      int buttonPin;
    public:
      Button(int buttonPin);
      void setup();
      bool isPressed();
};
#endif