#include "windowItem.hpp"

WindowItem::WindowItem(Shape *shape) : shape(shape) {};

void WindowItem::render()
{
  shape->render();
}
