#include "button.h"
Button::Button(int buttonPin) {
  this->buttonPin = buttonPin;
}

void Button::setup() {
  // set the pin mode
  pinMode(buttonPin, INPUT);
}

bool Button::isPressed() {
  // get the state of the button
  return digitalRead(this->buttonPin);
}