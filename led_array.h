#ifndef LedArray_h
#define LedArray_h
#include "Arduino.h"
#include <FastLED.h>
#include "timer.h"
#include "analog_reader.h"
class LedArray {
    protected:
      CRGB leds[21];
      int whiteLEDCount = 6;
      int colourLEDCount = 15;
      int whiteLEDs[6] = { 1, 3, 5, 7, 9, 11 };
      int colourLEDs[16] = { 0, 2, 4, 6, 8, 10, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };

      unsigned int maxWhiteBrightness = 170;
      unsigned int minWhiteBrightness = 65;
      unsigned int maxRedBrightness = 255;
      unsigned int minRedBrightness = 75;
      unsigned int maxBlueBrightness = 255;
      unsigned int minBlueBrightness = 75;
      float whiteBrightness = 1.0;
      float redBrightness = 1.0;
      float blueBrightness = 1.0;
      float brightness = 1.0;
      int flashDuration = 1000;
      Timer timer = Timer();
      Timer delayTimer = Timer();
      bool on = false;
      AnalogReader analogReader = AnalogReader(A2, 100); // analog pin, readIntervalMS

      void veryCold();
      void cold();
      void warm();
      void hot();
      void veryHot();
      void setLeds(int number_of_leds, int *led_array, CHSV colour);
    public:
        LedArray(unsigned int flashDuration);
        void setup();
        void setTemperature(float temperature);
};
#endif