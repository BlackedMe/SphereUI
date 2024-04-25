#pragma  once
#include <glad/glad.h>
#include <glm/vec2.hpp>
class Renderable{
public:
  virtual void render() = 0;

  void setPos(const glm::vec2 &pos);
  const glm::vec2 &getPos();
protected:
  //data
  GLuint vao = 0;
  glm::vec2 pos;
};
