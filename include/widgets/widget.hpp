#pragma once
#include "boxModel.hpp"
#include "shape.hpp"
#include "behaviors/transform/transform.hpp"
#include "behaviors/click/clickBehavior.hpp"

class Widget : public Renderable{
public:
  Widget(float width, float height, Shapes id, GLuint program);
  void render() override;
  BoxModel &geometry();
  Transform &transform();

private:
  //components
  Shape *shape;
  BoxModel bm;
  Transform transformation;

  //dependencies
  GLuint program;
};
