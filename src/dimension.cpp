#include "dimension.hpp"

Dimension::Dimension() {};

Dimension::Dimension(float width, float height) : width(width), height(height) {};

float Dimension::getWidth()
{
  return width;
}

float Dimension::getHeight()
{
  return height;
}

void Dimension::setDimension(float width, float height)
{
  this->width = width;
  this->height = height;
}
