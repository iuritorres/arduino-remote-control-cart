#include <Arduino.h>

#include "modules/Controller/Controller.h"
#include "modules/Wheel/Wheel.h"

Controller controller(0, 1);
Wheel leftWheel("Left Wheel", 3, 5, 6);
Wheel rightWheel("Right Wheel", 11, 10, 9);

void setup()
{
  Serial.begin(9600);
  controller.begin();

  Serial.println("Starting the Arduino application...");

  leftWheel.setupPins();
  rightWheel.setupPins();

  controller.subscribe(&leftWheel);
  controller.subscribe(&rightWheel);
}

void loop()
{
  controller.listen();
}
