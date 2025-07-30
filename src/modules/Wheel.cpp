#include <Arduino.h>

class Wheel
{
private:
  int _enablePin;
  int _positivePin;
  int _negativePin;

public:
  Wheel(int enablePin, int positivePin, int negativePin)
      : _enablePin(enablePin), _positivePin(positivePin), _negativePin(negativePin)
  {
    pinMode(_enablePin, OUTPUT);
    pinMode(_positivePin, OUTPUT);
    pinMode(_negativePin, OUTPUT);
  }

  void setSpeed(int speed)
  {
    analogWrite(_enablePin, speed);
  }

  void stop()
  {
    digitalWrite(_positivePin, LOW);
    digitalWrite(_negativePin, LOW);
    analogWrite(_enablePin, 0);
  }

  void forward()
  {
    digitalWrite(_positivePin, HIGH);
    digitalWrite(_negativePin, LOW);
  }

  void backward()
  {
    digitalWrite(_positivePin, LOW);
    digitalWrite(_negativePin, HIGH);
  }
};
