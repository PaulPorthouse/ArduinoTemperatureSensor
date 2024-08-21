#include "Arduino.h"
#include "temperature.h"
#include "timer.h"

Temperature::Temperature(int thermistorPin, int tempReadIntervalMS) {
  this->thermistorPin = thermistorPin;
  this->tempReadIntervalMS = tempReadIntervalMS;
  this->timer = Timer();
  this->temperature = 0.0;
}

void Temperature::setup() {
  // read the initial temperature
  this->readTemperature();
}

void Temperature::readTemperature() {
  // https://www.circuitbasics.com/arduino-thermistor-temperature-sensor-tutorial/
  // read the temperature from the thermistor
  int Vo;
  float R1 = 10000; // 10000 originally
  float logR2, R2, T;
  float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

  Vo = analogRead(this->thermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;

  this->temperature = T;
}

float Temperature::getTemperature() {
  // only read the temp if the last read was more than
  // `tempReadIntervalMS` ms ago, otherwise return the 
  // previously read temperature
  if (timer.getIntervalMilliseconds() > this->tempReadIntervalMS) {
    timer.createInterval();
    this->readTemperature();
  }

  return this->temperature;
}