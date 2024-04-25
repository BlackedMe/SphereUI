#include "renderable.hpp"

void Renderable::setPos(const glm::vec2 &pos)
{
  this->pos = pos;
}

const glm::vec2 &Renderable::getPos()
{
  return pos;
}
