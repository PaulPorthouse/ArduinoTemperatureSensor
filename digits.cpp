#include "Arduino.h"
#include "digits.h"
#include "timer.h"

Digits::Digits(int buttonDisplayDuration) {
  this->buttonDisplayDuration = buttonDisplayDuration;
}

void Digits::setup() {
  // set up the pin modes
  pinMode(this->d1Pin, OUTPUT);
  pinMode(this->d2Pin, OUTPUT);
  for (int i = 0; i < 8; i++) {
    pinMode(this->dataPins[i], OUTPUT);
  }

  // set the d1 and d2 pins to their initial state
  this->clearDisplay();
}

void Digits::clearDisplay() {
  // set the d1 and d2 pins state to disabled
  digitalWrite(this->d1Pin, LOW);
  digitalWrite(this->d2Pin, LOW);
};

void Digits::displayDigit(int digit, int value) {
  // enable the relevant digit, and disable the other one
	if (digit == 0) {
		digitalWrite(this->d1Pin, LOW);
		digitalWrite(this->d2Pin, HIGH);
	} else {
		digitalWrite(this->d1Pin, HIGH);
		digitalWrite(this->d2Pin, LOW);
	}

  // set the pins to display the selected digit
  int pinValue = 0;
  for (int i = 0; i < 8; i++) {
    if (this->digits[value] & (1 << i)) {
      pinValue = 0;
    } else {
      pinValue = 1;
    }
    digitalWrite(this->dataPins[i], pinValue);
  }
}

void Digits::displayValue(int value) {
  // split the value into it's separate digits
	int tens = value / 10;
	int ones = value % 10;
  this->values[0] = tens;
  this->values[1] = ones;
  this->displayTimer.createInterval();
}

void Digits::loop() {
  if (this->displayTimer.getIntervalMilliseconds() >= this->buttonDisplayDuration) {
    // display the values only for a certain time
    this->clearDisplay();
    return;
  }

  // display a certain digit for 10ms, then switch to the other
  if (this->digitTimer.getIntervalMilliseconds() > 10) {
    if (this->dToDisplay == 0) {
      this->dToDisplay = 1;
    } else {
      this->dToDisplay = 0;
    }
    this->digitTimer.createInterval();
  }

  this->displayDigit(this->dToDisplay, this->values[this->dToDisplay]);
}