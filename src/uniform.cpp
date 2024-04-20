#include "uniform.hpp"
#include "glad/glad.h"
#include <string>

void uniformMatrix4fv(GLuint program, std::string name, GLsizei count, GLboolean transpose, const GLfloat *value)
{
  glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()), count, transpose, value);
}
