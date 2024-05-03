#pragma once
#include "glm/ext/vector_float2.hpp"
class Transformable{
public:
  virtual void setPos(const glm::vec2 &pos) = 0;
  virtual const glm::vec2 &getPos() = 0;
};
