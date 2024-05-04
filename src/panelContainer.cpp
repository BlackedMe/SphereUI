#include "panel/panelContainer.hpp"
#include "panel/panelComponent.hpp"
#include "panel/containerHelper.hpp"

PanelContainer::PanelContainer(float width, float height)
{
  current = this;

  bm.setContent(width, height);
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
    firstContainer = new PanelContainer(current->geometry().getMargin().x, component->geometry().getMargin().y);
    secondContainer = new PanelContainer(current->geometry().getMargin().x, current->geometry().getMargin().y - component->geometry().getMargin().y);
  }
  if(alignment == SP_LEFT || alignment == SP_RIGHT)
  {
    firstContainer = new PanelContainer(component->geometry().getMargin().x, current->geometry().getMargin().y);
    secondContainer = new PanelContainer(current->geometry().getMargin().x - component->geometry().getMargin().x, current->geometry().getMargin().y);
  }

  helper->align(current, firstContainer);
  component->transform().setPos(firstContainer->transform().getPos());
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

BoxModel &PanelContainer::geometry()
{
  return bm;
}

Transform &PanelContainer::transform()
{
  return transformation;
}
