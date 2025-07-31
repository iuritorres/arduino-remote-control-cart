#include <observer/Observer.h>

#ifndef Subject_h
#define Subject_h

class Subject
{
private:
  static const int MAX_OBSERVERS_COUNT = 5;

  Observer *observers[Subject::MAX_OBSERVERS_COUNT];

public:
  Subject();

  void subscribe(Observer *observer);
  void unsubscribe(Observer *observer);
  void notify(void *data);
};

#endif
