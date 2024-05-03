#include "panelComponent.hpp"
#include "panelContainer.hpp"
#include <glm/vec2.hpp>
class ContainerHelper{
public:
  void align(PanelContainer *container, PanelComponent *component);
  virtual void containerPushBack(PanelContainer *container, PanelComponent *component) = 0;
protected:
  //sets component to the initial position relative to the container
  virtual void initalizeComponentPos(PanelContainer *container, PanelComponent *component) = 0;
  virtual void setComponentPos(PanelContainer *container, PanelComponent *component) = 0;
  virtual bool isContainerEmpty(PanelContainer *container, PanelComponent *component) = 0;
};

class B_ContainerHelper : public ContainerHelper{
public:
  void containerPushBack(PanelContainer *container, PanelComponent *component) override;
private:
  void initalizeComponentPos(PanelContainer *container, PanelComponent *component) override;
  void setComponentPos(PanelContainer *container, PanelComponent *component) override;
  bool isContainerEmpty(PanelContainer *container, PanelComponent *component) override;
};

class R_ContainerHelper : public ContainerHelper{
public:
  void containerPushBack(PanelContainer *container, PanelComponent *component) override;
private:
  void initalizeComponentPos(PanelContainer *container, PanelComponent *component) override;
  void setComponentPos(PanelContainer *container, PanelComponent *component) override;
  bool isContainerEmpty(PanelContainer *container, PanelComponent *component) override;
};

class T_ContainerHelper : public ContainerHelper{
public:
  void containerPushBack(PanelContainer *container, PanelComponent *component) override;
private:
  void initalizeComponentPos(PanelContainer *container, PanelComponent *component) override;
  void setComponentPos(PanelContainer *container, PanelComponent *component) override;
  bool isContainerEmpty(PanelContainer *container, PanelComponent *component) override;
};

class L_ContainerHelper : public ContainerHelper{
public:
  void containerPushBack(PanelContainer *container, PanelComponent *component) override;
private:
  void initalizeComponentPos(PanelContainer *container, PanelComponent *component) override;
  void setComponentPos(PanelContainer *container, PanelComponent *component) override;
  bool isContainerEmpty(PanelContainer *container, PanelComponent *component) override;
};

