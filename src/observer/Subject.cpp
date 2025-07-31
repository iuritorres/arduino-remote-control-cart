#include <observer/Observer.h>
#include <observer/Subject.h>

Subject::Subject()
{
}

void Subject::subscribe(Observer *observer)
{
  for (int i = 0; i < MAX_OBSERVERS_COUNT; i++)
  {
    if (observers[i] != nullptr)
    {
      continue;
    }

    observers[i] = observer;
    break;
  }
}

void Subject::unsubscribe(Observer *observer)
{
  for (int i = 0; i < MAX_OBSERVERS_COUNT; i++)
  {
    if (observers[i] != observer)
    {
      continue;
    }

    observers[i] = nullptr;
    break;
  }
}

void Subject::notify(void *data)
{
  for (int i = 0; i < MAX_OBSERVERS_COUNT; i++)
  {
    if (observers[i] == nullptr)
    {
      return;
    }

    observers[i]->update(data);
  }
}