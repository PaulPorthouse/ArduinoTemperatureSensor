#include "timer.h"
Timer::Timer() {
    this->startMilliseconds = millis();
    this->lastIntervalMilliseconds = this->startMilliseconds;
};

void Timer::setup() {}

unsigned long Timer::getTotalMilliseconds() {
  // return the number of ms that the program has
  // been running
  return millis() - this->startMilliseconds;
}

unsigned long Timer::getIntervalMilliseconds() {
  // return the number of ms since the interval
  // was created
  return millis() - this->lastIntervalMilliseconds;
}

void Timer::createInterval() {
  // create an interval
  this->lastIntervalMilliseconds = millis();
}