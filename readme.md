# Arduino Temperature Sensor

This project is a temperature sensor that can visually alert the user when the
temperature gets outside of a specific range.

# Disclaimer

I am fairly new to Arduino and C++ programming (although I am a programmer), so
the code here is liable not to be best practice (or even good), but I'm learning
as I go, so it *should* get better.

# Schematic
[PDF of schematic](documentation/schematic.pdf)

# Parts List

* 1 x [Arduino Nano Every](https://store.arduino.cc/products/arduino-nano-every?srsltid=AfmBOooqk8AtTgJYrkSKT_WR8lKfO9X7QG-1voyWMmZsvvH6m3fgy-Z-) [A1]
* 1 x [GND-5021BS](https://www.rcscomponents.kiev.ua/datasheets/GND-5021Ax-Bx.pdf) [U1]
* 1 x [61 x WS2812 RGB LED Ring Lamp](https://amzn.eu/d/0VMO4f6) [NOT CURRENTLY SHOWN]
* 1 x SPST Momentary switch [SW2]
* 1 x 10K Variable resistor with switch [SW1] [RV1]
* 8 x 470R resistors [R1 - R8]
* 1 x 10K NTC Thermistor bead [TH1]
* 1 x 10K resistor [R9]

# Operation

* [SW1] is used to switch the device on or off
* [RV1] is used to control the brightness of the LED ring
* [TH1] is used to provide the current temperature and is used with [R9] to work like a variable resistor
* [R1 - R8] are used as current-limiting resistors to protect the seven segment displays
* [U1] is a dual seven segment display but only uses 10 pins as it has digit selector pins and is used to display the current temperature for 3 seconds when [SW2] is pressed
* [A1] is the heart of the system and drives everything else
* [NOT CURRENTLY SHOWN] The LED ring is used underneath a diffuser to light up under certain configurations
  * White LEDs are always on to provide a night light function
  * Blue LEDs flash when the temperature is below 14&deg;C to indicate it is very cold
  * Blue LEDs on permanently when temperature is between 14&deg;C and 16&deg;C to indicate it is cold
  * Red LEDs on permanently when temperature is between 20&deg;C and 22&deg;C to indicate it is hot
  * Red LEDs flash when the temperature is above 22&deg;C to indicate it is very hot