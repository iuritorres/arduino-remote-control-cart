#ifndef Observer_h
#define Observer_h

class Observer
{
private:
  char *_name;

public:
  Observer(char *name);

  virtual void update(void *data);
};

#endif
