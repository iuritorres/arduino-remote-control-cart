#include <Arduino.h>
#include <SoftwareSerial.h>

#include "Controller.h"

const KeyMap Controller::keyActionMap[] = {
    // DIRECTIONAL KEYS
    {KeyAction::FORWARD, "F"},
    {KeyAction::BACKWARD, "B"},
    {KeyAction::LEFT, "L"},
    {KeyAction::RIGHT, "R"},

    // BUTTON KEYS
    {KeyAction::SQUARE, "S"},
    {KeyAction::TRIANGLE, "T"},
    {KeyAction::CIRCLE, "C"},
    {KeyAction::CROSS, "X"},

    // ACTION KEYS
    {KeyAction::START, "A"},
    {KeyAction::PAUSE, "P"}};

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

    if (command)
    {
      KeyAction action = static_cast<KeyAction>(command);
      notify(&action);
    }
  }
}
