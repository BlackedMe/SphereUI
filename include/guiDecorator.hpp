#pragma once
#include "guiComponent.hpp"
class GUIDecorator : public GUIComponent{
protected:
  GUIDecorator(GUIComponent* component);

  void render() override;
protected:
  GUIComponent* component;
};
