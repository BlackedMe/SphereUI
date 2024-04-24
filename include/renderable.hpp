#pragma  once
#include <glad/glad.h>
#include <glm/vec2.hpp>
class Renderable{
public:
  virtual void render() = 0;
  static void setProgram(GLuint program);
  void setPos(const glm::vec2 &pos);
protected:
  GLuint vao = 0;
  glm::vec2 pos;

  GLuint getProgram();
private:
  static GLuint program;
};
