#pragma once
#include <glm/vec2.hpp>
class GUIComponent{
public:
  virtual void create() = 0;
  virtual void listen() = 0;
  virtual void render() = 0;

  void setPos(const glm::vec2 &pos);
protected:
  glm::vec2 pos;
};
