#pragma once
#include "renderable.hpp"
class GUIComponent : public Renderable{
public:
  virtual void add(GUIComponent *component) {};
  virtual void remove(GUIComponent *component) {};
};
