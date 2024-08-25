#include "Arduino.h"
#include "analog_reader.h"

AnalogReader::AnalogReader(int analogPin, int readIntervalMS) {
  this->analogPin = analogPin;
  this->readIntervalMS = readIntervalMS;
  this->timer = Timer();
  this->value = 0;
}

void AnalogReader::setup() {
  // read the initial temperature
  pinMode(this->analogPin, INPUT);
  this->value = analogRead(this->analogPin);
}

int AnalogReader::readValue() {
  // check to make sure we want to read the value
  if (timer.getIntervalMilliseconds() > this->readIntervalMS) {
    // yes, so create a new interval
    timer.createInterval();
    // read the value into our local `value` variable
    this->value = analogRead(this->analogPin);
  }
  // return the local `value` variable
  return this->value;
}

int AnalogReader::getValue() {
  return this->readValue();
}

float AnalogReader::getNormalisedValue() {
  // return a value from 0 -> 1
  return (float)this->readValue() / 1024.0;
}