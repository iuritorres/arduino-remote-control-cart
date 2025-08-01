#include <Arduino.h>

#include "Wheel.h"
#include "../Controller/KeyCommand.h"

Wheel::Wheel(char *name, WheelSide side, int enablePin, int positivePin, int negativePin)
    : Observer(name), _side(side), _enablePin(enablePin), _positivePin(positivePin), _negativePin(negativePin)
{
}

void Wheel::setupPins()
{
  pinMode(_enablePin, OUTPUT);
  pinMode(_positivePin, OUTPUT);
  pinMode(_negativePin, OUTPUT);
}

void Wheel::stop()
{
  digitalWrite(_positivePin, LOW);
  digitalWrite(_negativePin, LOW);

  analogWrite(_enablePin, 0);
}

void Wheel::forward(int speed)
{
  digitalWrite(_positivePin, HIGH);
  digitalWrite(_negativePin, LOW);

  analogWrite(_enablePin, speed);
}

void Wheel::backward(int speed)
{
  digitalWrite(_positivePin, LOW);
  digitalWrite(_negativePin, HIGH);

  analogWrite(_enablePin, speed);
}

void Wheel::update(void *data)
{
  char action = *static_cast<char *>(data);

  Serial.print("Wheel update received action: ");
  Serial.println(action);

  switch (action)
  {
  case KeyCommand::FORWARD:
    forward();
    break;

  case KeyCommand::BACKWARD:
    backward();
    break;

  case KeyCommand::LEFT:
    _side == LEFT ? stop() : forward();
    break;

  case KeyCommand::RIGHT:
    _side == RIGHT ? stop() : forward();
    break;

  case KeyCommand::SQUARE:
  case KeyCommand::TRIANGLE:
    break;

  case KeyCommand::CIRCLE:
    stop();
    break;

  case KeyCommand::CROSS:
  case KeyCommand::START:
  case KeyCommand::PAUSE:
    break;

  default:
    stop();
    break;
  }
}
