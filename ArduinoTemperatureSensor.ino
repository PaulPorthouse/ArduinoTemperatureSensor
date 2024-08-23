#include "temperature.h"
#include "digits.h"
#include "button.h"
#include "timer.h"

const int DISPLAY_BUTTON_PIN        = 14;
const int THERMISTOR_PIN            = 7;
const int TEMP_READ_INTERVAL        = 1000;
const int BUTTON_DISPLAY_DURATION   = 3000;

Digits digits = Digits();
Temperature temperature = Temperature(THERMISTOR_PIN, TEMP_READ_INTERVAL);
Button button = Button(DISPLAY_BUTTON_PIN);
Timer buttonTimer = Timer();

bool display = false;

void setup() {
  // run setup for all of the components
  digits.setup();
  temperature.setup();
  button.setup();
  buttonTimer.setup();
}

void loop() {
  // only display the temperature if the button has been pressed during the 
  // previous `BUTTON_DISPLAY_DURATION` ms
  if (button.isPressed() || buttonTimer.getIntervalMilliseconds() < BUTTON_DISPLAY_DURATION){
    if (button.isPressed()) {
      buttonTimer.createInterval();
    }
    digits.displayValue(temperature.getTemperature());
  } else {
    digits.clearDisplay();
  }
}
