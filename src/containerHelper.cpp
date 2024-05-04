#include "panel/containerHelper.hpp"
#include "panel/panelContainer.hpp"
#define posX(item) item->transform().getPos().x
#define posY(item) item->transform().getPos().y
#define width(item) item->geometry().getMargin().x
#define height(item) item->geometry().getMargin().y

void ContainerHelper::align(PanelContainer *container, PanelComponent *component)
{
  if(isContainerEmpty(container, component))
  {
    initalizeComponentPos(container, component);
    return;
  }
  
  setComponentPos(container, component);
}

void B_ContainerHelper::containerPushBack(PanelContainer *container, PanelComponent *component) 
{
  container->bottom.push_back(component);
}

void B_ContainerHelper::initalizeComponentPos(PanelContainer *container, PanelComponent *component)
{
  component->transform().setPos(glm::vec2(posX(container), posY(container) + (height(component) - height(container))/2));
}

void B_ContainerHelper::setComponentPos(PanelContainer *container, PanelComponent *component)
{
  component->transform().setPos(glm::vec2(posX(container->bottom.back()), posY(container->bottom.back()) + (height(component) + height(container->bottom.back()))/2));
}

bool B_ContainerHelper::isContainerEmpty(PanelContainer *container, PanelComponent *component)
{
  return container->bottom.empty();
}

void R_ContainerHelper::containerPushBack(PanelContainer *container, PanelComponent *component) 
{
  container->right.push_back(component);
}

void R_ContainerHelper::initalizeComponentPos(PanelContainer *container, PanelComponent *component)
{
  component->transform().setPos(glm::vec2(posX(container) + width(container)/2 - width(component)/2, posY(container)));
}

void R_ContainerHelper::setComponentPos(PanelContainer *container, PanelComponent *component)
{
  component->transform().setPos(glm::vec2(posX(container->right.back()) - width(container->right.back())/2 - width(component)/2, posY(container->right.back())));
}

bool R_ContainerHelper::isContainerEmpty(PanelContainer *container, PanelComponent *component)
{
  return container->right.empty();
}

void T_ContainerHelper::containerPushBack(PanelContainer *container, PanelComponent *component) 
{
  container->top.push_back(component);
}

void T_ContainerHelper::initalizeComponentPos(PanelContainer *container, PanelComponent *component)
{
  component->transform().setPos(glm::vec2(posX(container), posY(container) + height(container)/2 - height(component)/2));
}

void T_ContainerHelper::setComponentPos(PanelContainer *container, PanelComponent *component)
{
  component->transform().setPos(glm::vec2(posX(container->top.back()), posY(container->top.back()) - height(container->top.back())/2 - height(component)/2));
}

bool T_ContainerHelper::isContainerEmpty(PanelContainer *container, PanelComponent *component)
{
  return container->top.empty();
}

void L_ContainerHelper::containerPushBack(PanelContainer *container, PanelComponent *component) 
{
  container->left.push_back(component);
}

void L_ContainerHelper::initalizeComponentPos(PanelContainer *container, PanelComponent *component)
{
  component->transform().setPos(glm::vec2(posX(container) - width(container)/2 + width(component)/2, posY(container)));
}

void L_ContainerHelper::setComponentPos(PanelContainer *container, PanelComponent *component)
{
  component->transform().setPos(glm::vec2(posX(container->left.back()) + width(container->left.back())/2 + width(component)/2, posY(container->left.back())));
}

bool L_ContainerHelper::isContainerEmpty(PanelContainer *container, PanelComponent *component)
{
  return container->left.empty();
}
