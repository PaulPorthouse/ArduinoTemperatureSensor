#include "button.h"
Button::Button(int buttonPin) {
  this->buttonPin = buttonPin;
}

void Button::setup() {
  // set the pin mode
  pinMode(buttonPin, INPUT_PULLUP);
}

bool Button::isPressed() {
  // get the state of the button (pressed = LOW, so invert)
  return !(digitalRead(this->buttonPin));
}