#pragma once

#include <SoftwareSerial.h>

#include <observer/Subject.h>

class Controller : public Subject
{
private:
  SoftwareSerial bluetooth;

public:
  Controller(int rxPin, int txPin);

  void begin();
  void listen();
};
