#pragma once
#include "renderable.hpp"
class PanelComponent : public Renderable{
public:
  virtual void add(PanelComponent *component) {};
  virtual void remove(PanelComponent *component) {};
};
