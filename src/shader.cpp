#include "shader.hpp"
#include "parser.hpp"
#include "uniform.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_float4x4.hpp"
#include <iostream>

GLuint Shader::compileShader(GLenum type, const char* src)
{
  const char* shaderSrc = parseFromFile(src);
  GLuint shaderObj = glCreateShader(type);
  glShaderSource(shaderObj, 1, &shaderSrc, 0);
  glCompileShader(shaderObj);

  GLint compileStatus;
  glGetShaderiv(shaderObj, GL_COMPILE_STATUS, &compileStatus);

  if(compileStatus != GL_TRUE)
  {
    GLsizei length;
    GLchar *infoLog = new GLchar[1024];
    glGetShaderInfoLog(shaderObj, 1024, &length, infoLog);
    std::cout << infoLog << '\n';
  }
  return shaderObj;
}

void Shader::init(const char* vShaderSrc, const char* fShaderSrc, float aspectRatio)
{
  GLuint vShader = compileShader(GL_VERTEX_SHADER, "../assets/shader/vShader.glsl");
  GLuint fShader = compileShader(GL_FRAGMENT_SHADER, "../assets/shader/fShader.glsl");
  
  program = glCreateProgram();
  glAttachShader(program, vShader);
  glAttachShader(program, fShader);
  glLinkProgram(program);

  GLint linkStatus;
  glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
  
  if(linkStatus != GL_TRUE)
  {
    GLsizei length;
    GLchar *infoLog = new GLchar[1024];
    glGetProgramInfoLog(program, 1024, &length, infoLog);
    std::cout << infoLog << '\n';
  }
  
  //initalizes default uniform values
  glm::mat4 model(1.0f), view(1.0f), proj(1.0f);
  proj = glm::ortho(-aspectRatio, aspectRatio, -1.0f, 1.0f);
  glUseProgram(program);
  uniformMatrix4fv(program, "model", 1, GL_FALSE, &model[0][0]); 
  uniformMatrix4fv(program, "view", 1, GL_FALSE, &view[0][0]); 
  uniformMatrix4fv(program, "proj", 1, GL_FALSE, &proj[0][0]); 
  glUseProgram(0);
}

void Shader::useProgram()
{
  glUseProgram(program);
}
