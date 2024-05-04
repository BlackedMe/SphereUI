#pragma once
#include "renderable.hpp"
#include <glad/glad.h>

enum Shapes{
  SP_RECTANGLE = 0,
};

class Shape : public Renderable{
public:
  static Shape *create(Shapes id, float width, float height);
protected:
  GLuint vao;
};

class Rectangle : public Shape{
public:
  Rectangle(float width, float height);

  void render() override;
};
