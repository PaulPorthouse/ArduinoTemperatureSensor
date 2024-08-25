#include "led_array.h"

LedArray::LedArray(unsigned int flashDuration) {
  this->flashDuration = flashDuration;
}

void LedArray::setup() {
  pinMode(15, OUTPUT);
  this->timer.createInterval();
  this->delayTimer.createInterval();
  this->on = false;

  // put your setup code here, to run once:
  FastLED.addLeds<WS2812, 15, GRB>(this->leds, 21);

  this->setLeds(this->whiteLEDCount, this->whiteLEDs, CHSV(0, 0, this->whiteBrightness));
  this->analogReader.setup();
}

void LedArray::setTemperature(float temperature) {
  this->brightness = this->analogReader.getNormalisedValue();
  this->whiteBrightness = ((this->maxWhiteBrightness - this->minWhiteBrightness) * this->brightness) + this->minWhiteBrightness;
  this->redBrightness = ((this->maxRedBrightness - this->minRedBrightness) * this->brightness) + this->minRedBrightness;
  this->blueBrightness = ((this->maxBlueBrightness - this->minBlueBrightness) * this->brightness) + this->minBlueBrightness;

  if (this->timer.getIntervalMilliseconds() > this->flashDuration) {
    this->timer.createInterval();
    // toggle flash state
    if (this->on) {
      // turn off
      this->on = false;
    } else {
      // turn on
      this->on = true;
    }
  }

  this->setLeds(this->whiteLEDCount, this->whiteLEDs, CHSV(0, 0, this->whiteBrightness));

  if (temperature < 14.0) { veryCold(); }
  if (temperature >= 14.0 && temperature < 16.0) { cold(); }
  if (temperature >= 16.0 && temperature < 20.0) { warm(); }
  if (temperature >= 20.0 && temperature < 22.0) { hot(); }
  if (temperature >= 22.0) { veryHot(); }

  if (this->delayTimer.getIntervalMilliseconds() > 500) {
    this->delayTimer.createInterval();
    FastLED.show();
  }
}

void LedArray::veryCold() {
  CHSV colour = CHSV(240, 255, this->blueBrightness); // Blue
  if (!this->on) {
    colour = CHSV(0, 0, 0); // Black
  }
  this->setLeds(this->colourLEDCount, this->colourLEDs, colour);
}

void LedArray::cold() {
  this->setLeds(this->colourLEDCount, this->colourLEDs, CHSV(240, 255, this->blueBrightness));
}

void LedArray::warm() {
  this->setLeds(this->colourLEDCount, this->colourLEDs, CHSV(0, 0, this->whiteBrightness));
}

void LedArray::hot() {
  this->setLeds(this->colourLEDCount, this->colourLEDs, CHSV(0, 255, this->redBrightness));
}

void LedArray::veryHot() {
  CHSV colour = CHSV(0, 255, this->redBrightness); // Red
  if (!this->on) {
    colour = CHSV(0, 0, 0); // Black
  }
  this->setLeds(this->colourLEDCount, this->colourLEDs, colour);
}

void LedArray::setLeds(int number_of_leds, int *led_array, CHSV colour) {
  // set the specified LEDs to the specified colour in the LED array
  for (int i = 0; i < number_of_leds; i++) {
    leds[led_array[i]] = colour;
  }
}
