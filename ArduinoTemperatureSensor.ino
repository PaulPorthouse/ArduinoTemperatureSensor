#include "temperature.h"
#include "digits.h"
#include "button.h"
#include "timer.h"
#include "led_array.h"

const int DISPLAY_BUTTON_PIN        = 14;
const int THERMISTOR_PIN            = 7;
const int TEMP_READ_INTERVAL        = 5000; // ms
const int BUTTON_DISPLAY_DURATION   = 3000; // ms
const int LED_ARRAY_FLASH_DURATION  = 500; // ms

Digits digits = Digits(BUTTON_DISPLAY_DURATION);
Temperature temperature = Temperature(THERMISTOR_PIN, TEMP_READ_INTERVAL);
Button button = Button(DISPLAY_BUTTON_PIN);
Timer buttonTimer = Timer();
LedArray ledArray = LedArray(LED_ARRAY_FLASH_DURATION);

bool display = false;

void setup() {
  // run setup for all of the components
  digits.setup();
  temperature.setup();
  button.setup();
  buttonTimer.setup();
  ledArray.setup();

  Serial.begin(115200);
}

void loop() {
  ledArray.setTemperature(temperature.getTemperature());

  // only display the temperature if the button has been pressed during the
  // previous `BUTTON_DISPLAY_DURATION` ms
  if (button.isPressed()) {
    digits.displayValue(temperature.getTemperature());
  }

  // if (button.isPressed() || buttonTimer.getIntervalMilliseconds() < BUTTON_DISPLAY_DURATION){
  //   if (button.isPressed()) {
  //     buttonTimer.createInterval();
  //   }
  //   digits.displayValue(temperature.getTemperature());
  // } else {
  //   digits.clearDisplay();
  // }

  digits.loop();
}
