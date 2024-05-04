#pragma once
#include "panelComponent.hpp"
#include "behaviors/transform/transform.hpp"
#include <vector>
class PanelContainer : public PanelComponent{
public:
  PanelContainer(float width, float height);
  void add(PanelComponent *component, Alignment alignment) override;
  void render() override;
  BoxModel &geometry() override;
  Transform &transform() override;
private:
  std::vector<PanelComponent *> bottom;
  std::vector<PanelComponent *> right;
  std::vector<PanelComponent *> top;
  std::vector<PanelComponent *> left;

  PanelContainer *current;
  BoxModel bm;
  Transform transformation;

  friend class B_ContainerHelper; 
  friend class R_ContainerHelper;
  friend class T_ContainerHelper;
  friend class L_ContainerHelper;
};
