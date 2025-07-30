#include <Arduino.h>
#include "modules/Wheel.h"

Wheel leftWheel(3, 5, 6);
Wheel rightWheel(11, 10, 9);

void setup()
{
  leftWheel.setupPins();
  rightWheel.setupPins();

  Serial.begin(9600);
  Serial.println("Starting the Arduino application...");
}

void loop()
{
  leftWheel.forward();
  rightWheel.forward();

  delay(2000);

  leftWheel.backward();
  rightWheel.backward();

  delay(2000);

  leftWheel.stop();
  rightWheel.stop();

  delay(2000);
}
