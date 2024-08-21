#include "Arduino.h"
#include "digits.h"
#include "timer.h"

Digits::Digits() { }

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

  // display the first digit
	this->displayDigit(0, tens);
	delay(this->digitDelay);
  // display the second digit
	this->displayDigit(1, ones);
	delay(this->digitDelay);
}