#pragma once
#include "dimension.hpp"
#include "panelComponent.hpp"
#include "transform.hpp"
#include <vector>
class PanelContainer : public PanelComponent{
public:
  PanelContainer(float width, float height);
  void add(PanelComponent *component, Alignment alignment) override;
  void render() override;

  float getWidth() override;
  float getHeight() override;
  void setDimension(float width, float height) override;

  void setPos(const glm::vec2 &pos) override;
  const glm::vec2 &getPos() override;
  
private:
  std::vector<PanelComponent *> bottom;
  std::vector<PanelComponent *> right;
  std::vector<PanelComponent *> top;
  std::vector<PanelComponent *> left;

  PanelContainer *current;
  Dimension *dimension;
  Transform *transform;

  friend class B_ContainerHelper; 
  friend class R_ContainerHelper;
  friend class T_ContainerHelper;
  friend class L_ContainerHelper;
};
