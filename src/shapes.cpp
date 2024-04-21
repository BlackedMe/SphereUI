#include "shapes.hpp"

GLuint Shapes::genBox(float width, float height)
{
  width /= 2;
  height /= 2;

  GLuint vao = 0, vbo = 0, ebo = 0;

  float vertices[] = {
    -width, -height,
    width, -height,
    width, height,
    -width, height
  };
  
  unsigned int indices[] = {0, 1, 2, 2, 3, 0};
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

  return vao;
}
