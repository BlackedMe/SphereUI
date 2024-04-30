#pragma once
#include "renderable.hpp"
#include <glad/glad.h>
class Shape : public Renderable{
protected:
  GLuint vao, vbo;
};

class Rectangle : public Shape{
public:
  Rectangle(float width, float height);

  void render() override;
};
