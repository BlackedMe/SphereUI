#include "mouseHandler.hpp"

void Mouse::attach(Listener *listener)
{
  listeners.push_back(listener);
}

void Mouse::notify()
{
  for(Listener *n : listeners)
  {
    n->update(this);
  }
}

const glm::dvec2 &Mouse::getPos()
{
  return pos;
}

void Mouse::setPos(const glm::dvec2 &pos)
{
  this->pos = pos;
}
