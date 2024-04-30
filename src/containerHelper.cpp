#include "containerHelper.hpp"
#include "panelContainer.hpp"

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
  component->setPos(glm::vec2(container->getPos().x, container->getPos().y - container->getHeight()/2 + component->getHeight()/2));
}

void B_ContainerHelper::setComponentPos(PanelContainer *container, PanelComponent *component)
{
  component->setPos(glm::vec2(container->bottom.back()->getPos().x, container->bottom.back()->getPos().y + container->bottom.back()->getHeight()/2 + component->getHeight()/2));
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
  component->setPos(glm::vec2(container->getPos().x + container->getWidth()/2 - component->getWidth()/2, container->getPos().y));
}

void R_ContainerHelper::setComponentPos(PanelContainer *container, PanelComponent *component)
{
  component->setPos(glm::vec2(container->right.back()->getPos().x - container->right.back()->getWidth()/2 - component->getWidth()/2, container->right.back()->getPos().y));
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
  component->setPos(glm::vec2(container->getPos().x, container->getPos().y + container->getHeight()/2 - component->getHeight()/2));
}

void T_ContainerHelper::setComponentPos(PanelContainer *container, PanelComponent *component)
{
  component->setPos(glm::vec2(container->top.back()->getPos().x, container->top.back()->getPos().y - container->top.back()->getHeight()/2 - component->getHeight()/2));
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
  component->setPos(glm::vec2(container->getPos().x - container->getWidth()/2 + component->getWidth()/2, container->getPos().y));
}

void L_ContainerHelper::setComponentPos(PanelContainer *container, PanelComponent *component)
{
  component->setPos(glm::vec2(container->left.back()->getPos().x + container->left.back()->getWidth()/2 + component->getWidth()/2, container->left.back()->getPos().y));
}

bool L_ContainerHelper::isContainerEmpty(PanelContainer *container, PanelComponent *component)
{
  return container->left.empty();
}
