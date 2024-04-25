#pragma once
#include <glad/glad.h>
#include <glm/vec2.hpp>
class Renderable{
public:
  virtual void render() = 0;
};
