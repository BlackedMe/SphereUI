#pragma once
#include "glm/ext/vector_float2.hpp"
class Transformable{
public:
  void setPos(const glm::vec2 &pos);
protected:
  const glm::vec2 &getPos();
  glm::vec2 pos;
};
