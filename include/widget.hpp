#pragma once
#include "boxModel.hpp"
#include "shape.hpp"
#include "transform.hpp"
enum Widgets{
  SP_BUTTON = 0,
};

class Widget : public Renderable, public Transformable{
public:
  Widget(float width, float height, Shapes id, GLuint program);
  void render() override;

  //delegations
  void setPos(const glm::vec2 &pos) override;
  const glm::vec2 &getPos() override; 

  void setContent(float width, float height);
  void setPadding(float padX, float padY);

  float getBoxWidth();
  float getBoxHeight();
private:
  BoxModel *bm;
  Shape *shape;
  Transform *transform;
  //dependency
  GLuint program;
};
