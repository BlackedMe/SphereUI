#include "collision.hpp"

bool intersect(const AABB &aabb, const glm::vec2 &p)
{
  if(p.x < aabb.min.x || p.x > aabb.min.x)
  {
    return false;
  }

  if(p.y < aabb.min.y && p.y > aabb.max.y)
  {
    return false;
  }

  return true;
}
