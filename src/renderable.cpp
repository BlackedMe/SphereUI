#include "renderable.hpp"
#include <glad/glad.h>
GLuint Renderable::program = 0;

void Renderable::setProgram(GLuint program)
{
  Renderable::program = program;
}

void Renderable::setPos(const glm::vec2 &pos)
{
  Renderable::pos = pos;
}
GLuint Renderable::getProgram()
{
  return program;
}
