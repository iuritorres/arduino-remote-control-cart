#ifndef Wheel_h
#define Wheel_h

#include <observer/Observer.h>

class Wheel : public Observer
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
