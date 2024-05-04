#include "behaviors/transform/transform.hpp"

void Transform::setPos(const glm::vec2 &pos)
{
  this->pos = pos;
}

const glm::vec2 &Transform::getPos()
{
  return pos;
}

