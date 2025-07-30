#ifndef WHEEL_H
#define WHEEL_H

class Wheel
{
private:
  int _enablePin;
  int _positivePin;
  int _negativePin;

public:
  Wheel(int enablePin, int positivePin, int negativePin);

  void setupPins();
  void stop();
  void forward(int speed = 255);
  void backward(int speed = 255);
};

#endif
