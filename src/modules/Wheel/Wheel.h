#pragma once

#include <observer/Observer.h>

enum WheelSide
{
  LEFT,
  RIGHT
};

class Wheel : public Observer
{
private:
  WheelSide _side;
  int _enablePin;
  int _positivePin;
  int _negativePin;

public:
  Wheel(char *name, WheelSide side, int enablePin, int positivePin, int negativePin);

  void setupPins();
  void stop();
  void forward(int speed = 255);
  void backward(int speed = 255);

  void update(void *data) override;
};
