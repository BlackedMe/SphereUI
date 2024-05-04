#pragma once
#include "glm/ext/vector_float2.hpp"
class Dimension{
public:
  Dimension();
  Dimension(float width, float height);
  void setDimension(float width, float height);
  const glm::vec2 &getDimension();
private:
  glm::vec2 dimension;
};
