#ifndef WHEEL_H
#define WHEEL_H

class Wheel
{
public:
  Wheel(int enablePin, int positivePin, int negativePin);

private:
  int _enablePin;
  int _positivePin;
  int _negativePin;

  void setSpeed(int speed);
  void stop();
};

#endif
