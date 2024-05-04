#include "shape.hpp"

Shape *Shape::create(Shapes id, float width, float height)
{
  if(id == SP_RECTANGLE)
  {
    return new Rectangle(width, height);
  }
  return nullptr;
}

Rectangle::Rectangle(const glm::vec2 &dimension)
{
  create(dimension.x, dimension.y);
}

Rectangle::Rectangle(float width, float height) 
{
  create(width, height);
}

void Rectangle::render()
{
  glBindVertexArray(vao);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Rectangle::create(float width, float height)
{
  float vertices[] = {
    -width/2, -height/2,
     width/2, -height/2,
     width/2,  height/2,
    -width/2,  height/2,
  };

  unsigned int indices[] = {0, 1, 2, 2, 3, 0};
  GLuint vbo = 0, ebo = 0;

  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0], GL_STATIC_DRAW);

  glGenBuffers(1, &ebo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices[0], GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
}
