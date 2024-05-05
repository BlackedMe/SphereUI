#include "keyHandler.hpp"
#include "events/listener.hpp"

void MouseButton1::attach(Listener *listener)
{
  listeners.push_back(listener);
}

void MouseButton1::notify()
{
  for(Listener *n : listeners)
  {
    n->update(this);
  }
}

bool MouseButton1::getClickStatus()
{
  return isClicked;
}

