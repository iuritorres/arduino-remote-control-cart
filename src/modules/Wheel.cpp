#include <Arduino.h>
#include "Wheel.h"

Wheel::Wheel(int enablePin, int positivePin, int negativePin)
    : _enablePin(enablePin), _positivePin(positivePin), _negativePin(negativePin)
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

void Wheel::forward(int speed = 255)
{
  digitalWrite(_positivePin, HIGH);
  digitalWrite(_negativePin, LOW);

  analogWrite(_enablePin, speed);
}

void Wheel::backward(int speed = 255)
{
  digitalWrite(_positivePin, LOW);
  digitalWrite(_negativePin, HIGH);

  analogWrite(_enablePin, speed);
}
