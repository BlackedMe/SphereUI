#include "transformable.hpp"

void Transformable::setPos(const glm::vec2 &pos)
{
  this->pos = pos;
}

const glm::vec2 &Transformable::getPos()
{
  return pos;
}

