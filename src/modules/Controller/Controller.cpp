#include <Arduino.h>
#include <SoftwareSerial.h>

#include "Controller.h"

Controller::Controller(int rxPin, int txPin)
    : bluetooth(rxPin, txPin)
{
}

void Controller::begin()
{
  bluetooth.begin(9600);
}

void Controller::listen()
{
  if (bluetooth.available())
  {
    char command = bluetooth.read();
    Serial.print("Received command: ");
    Serial.println(command);

    if (!command)
    {
      return;
    }

    notify(&command);
  }
}
