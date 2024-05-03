#pragma once
#include "transformable.hpp"

class Transform : public Transformable{
public:
  void setPos(const glm::vec2 &pos) override;
  const glm::vec2 &getPos() override;
private:
  glm::vec2 pos = glm::vec2(0);
};
