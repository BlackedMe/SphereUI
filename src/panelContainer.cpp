#include "panelContainer.hpp"
#include "panelComponent.hpp"
#include "containerHelper.hpp"

PanelContainer::PanelContainer(float width, float height)
{
  current = this;

  dimension = new Dimension(width, height);

  transform = new Transform;
}

void PanelContainer::add(PanelComponent *component, Alignment alignment)
{
  ContainerHelper *helper;

  if(alignment == SP_BOTTOM) {
    helper = new B_ContainerHelper;
  }
  else if(alignment == SP_RIGHT) {
    helper = new R_ContainerHelper;
  }
  else if(alignment == SP_TOP) {
    helper = new T_ContainerHelper;
  }
  else {
    helper = new L_ContainerHelper;
  }

  PanelContainer *firstContainer; 
  PanelContainer *secondContainer;
  if(alignment == SP_TOP || alignment == SP_BOTTOM)
  {
    firstContainer = new PanelContainer(current->getWidth(), component->getHeight());
    secondContainer = new PanelContainer(current->getWidth(), current->getHeight() - component->getHeight());
  }
  if(alignment == SP_LEFT || alignment == SP_RIGHT)
  {
    firstContainer = new PanelContainer(component->getWidth(), current->getHeight());
    secondContainer = new PanelContainer(current->getWidth() - component->getWidth(), current->getHeight());
  }

  helper->align(current, firstContainer);
  component->setPos(firstContainer->getPos());
  helper->containerPushBack(firstContainer, component);
  helper->containerPushBack(current, firstContainer);
  
  helper->align(current, secondContainer);
  helper->containerPushBack(current, secondContainer);

  current = secondContainer;
}

void PanelContainer::render()
{
  for(PanelComponent *n : bottom)
  {
    n->render();
  }
  for(PanelComponent *n : right)
  {
    n->render();
  }
  for(PanelComponent *n : top)
  {
    n->render();
  }
  for(PanelComponent *n : left)
  {
    n->render();
  }
}

float PanelContainer::getWidth()
{
  return dimension->getWidth();
}

float PanelContainer::getHeight()
{
  return dimension->getHeight();
}

void PanelContainer::setPos(const glm::vec2 &pos) 
{
  transform->setPos(pos);
}

void PanelContainer::setDimension(float width, float height)
{
  dimension->setDimension(width, height);
}

const glm::vec2 &PanelContainer::getPos()
{
  return transform->getPos();
}

