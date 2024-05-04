#include "keyHandler.hpp"
#include "observer.hpp"

void MouseButton1::attach(Observer *observer)
{
  observers.push_back(observer);
}

void MouseButton1::notify()
{
  for(Observer *n : observers)
  {
    n->update(this);
  }
}
