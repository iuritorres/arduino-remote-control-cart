#pragma once
class Observer
{
private:
  const char *_name;

public:
  Observer(const char *name);

  virtual void update(void *data);
};
