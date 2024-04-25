#include "decorator.hpp"

Decorator::Decorator(Shape *shape) : shape(shape) {};
void Decorator::render()
{
  shape->render();
}

Hover::Hover(Shape *shape) : Decorator(shape) {};
