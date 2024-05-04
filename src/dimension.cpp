#include "dimension.hpp"

Dimension::Dimension() {};

Dimension::Dimension(float width, float height) {
  dimension.x = width;
  dimension.y = height;
};

const glm::vec2 &Dimension::getDimension()
{
  return dimension;
}

void Dimension::setDimension(float width, float height)
{
  dimension.x = width;
  dimension.y = height;
}
