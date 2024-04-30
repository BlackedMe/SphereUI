#include "panelItem.hpp"

PanelItem::PanelItem(Widget *widget) : widget(widget) {};

void PanelItem::add(PanelComponent *component, Alignment alignment)
{
   
}

void PanelItem::render()
{
  widget->render();
}

void PanelItem::setPos(const glm::vec2 &pos) 
{
  widget->setPos(pos);
}

const glm::vec2 &PanelItem::getPos()
{
  return widget->getPos();
}

float PanelItem::getWidth()
{
  return widget->getBoxWidth();
}

float PanelItem::getHeight()
{
  return widget->getBoxHeight();
}
void PanelItem::setDimension(float width, float height)
{

}
