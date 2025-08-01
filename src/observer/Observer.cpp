#include <Arduino.h>
#include "Observer.h"

Observer::Observer(const char *name) : _name(name)
{
}

void Observer::update(void *data)
{
  Serial.print("Observer ");
  Serial.print(_name);
  Serial.print(" received message: ");
  Serial.println(static_cast<char *>(data));
}
