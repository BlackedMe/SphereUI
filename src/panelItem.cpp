#include "panelItem.hpp"

PanelItem::PanelItem(Shape *shape) : shape(shape) {};

void PanelItem::render()
{
  shape->render();
}
