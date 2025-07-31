#ifndef Controller_h
#define Controller_h

#include <SoftwareSerial.h>

#include <observer/Subject.h>

enum class KeyAction
{
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT,

  SQUARE,
  TRIANGLE,
  CIRCLE,
  CROSS,

  START,
  PAUSE
};

struct KeyMap
{
  KeyAction key;
  const char *value;
};

class Controller : public Subject
{
private:
  SoftwareSerial bluetooth;
  static const KeyMap keyActionMap[];

public:
  Controller(int rxPin, int txPin);

  void begin();
  void listen();
};

#endif
