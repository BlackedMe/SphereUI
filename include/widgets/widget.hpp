#pragma once
#include "boxModel.hpp"
#include "events/listener.hpp"
#include "shape.hpp"
#include "behaviors/transform/transform.hpp"

class Widget : public Renderable, public Listener{
public:
  Widget(float width, float height, Shapes id, GLuint program);
  void render() override;

  BoxModel &geometry();
  Transform &transform();

  virtual void click() = 0;

  void update(Mouse *mouse) override;
protected:
  bool isHovered = false;
private:
  //components
  Shape *shape;
  BoxModel bm;
  Transform transformation;

  //dependencies
  GLuint program;
};
