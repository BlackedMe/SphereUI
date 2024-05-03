#pragma once
#include "renderable.hpp"
#include "behaviors/transform/transformable.hpp"

enum Alignment{
  SP_BOTTOM = 0,
  SP_RIGHT = 1,
  SP_TOP = 2,
  SP_LEFT = 3,
};

class PanelComponent : public Renderable, public Transformable{
public:
  virtual void add(PanelComponent *component, Alignment alignment) = 0;

  virtual float getWidth() = 0;
  virtual float getHeight() = 0;
  virtual void setDimension(float width, float height) = 0; 
};