#include "panel/panelItem.hpp"

PanelItem::PanelItem(Widget *widget) : widget(widget) {};

void PanelItem::add(PanelComponent *component, Alignment alignment)
{
   
}

void PanelItem::render()
{
  widget->render();
}

BoxModel &PanelItem::geometry()
{
  return widget->geometry();
}

Transform &PanelItem::transform()
{
  return widget->transform();
}
