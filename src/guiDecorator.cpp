#include "guiDecorator.hpp"
#include "guiComponent.hpp"

GUIDecorator::GUIDecorator(GUIComponent* component) : component(component) {};

void GUIDecorator::render()
{
  component->render(); 
}
