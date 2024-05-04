#pragma once
#include "boxModel.hpp"
#include "renderable.hpp"
#include "behaviors/transform/transform.hpp"

enum Alignment{
  SP_BOTTOM = 0,
  SP_RIGHT = 1,
  SP_TOP = 2,
  SP_LEFT = 3,
};

class PanelComponent : public Renderable{
public:
  virtual void add(PanelComponent *component, Alignment alignment) = 0;
  virtual BoxModel &geometry() = 0;
  virtual Transform &transform() = 0;
};
