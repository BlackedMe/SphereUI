#include "shape.hpp"

Rectangle::Rectangle(float width, float height) : width(width), height(height)
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

void Rectangle::render()
{
  glBindVertexArray(vao); 
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
