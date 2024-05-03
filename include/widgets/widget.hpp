#pragma once
#include "boxModel.hpp"
#include "shape.hpp"
#include "behaviors/transform/transform.hpp"
#include "behaviors/click/clickBehavior.hpp"
#include "aabb.hpp"

class Widget : public Renderable, public Transformable{
public:
  Widget(float width, float height, Shapes id, GLuint program);
  void render() override;

  //delegations
  void setPos(const glm::vec2 &pos) override;
  const glm::vec2 &getPos() override; 

  void setContent(float width, float height);
  void setPadding(float padX, float padY);
  void setBorder(float borderX, float borderY);
  void setMargin(float marginX, float marginY);

  float getBoxWidth();
  float getBoxHeight();

  void update();
protected:
  //components
  BoxModel *bm;
  Shape *shape;
  Transform *transform;
  ClickBehavior *clickBehavior;
  //dependencies
  GLuint program;
  glm::vec2 cursorPos;

  virtual void updateRequired() = 0;
};
