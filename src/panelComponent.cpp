#include "panelComponent.hpp"
#include "panelItem.hpp"

PanelComponent* PanelComponent::create(Widgets id)
{
  Widget *widget;
  if(id == SP_BUTTON)
  {
    widget = new Widget(0.2, 0.1, SP_RECTANGLE, program);
  }
  return nullptr;
}
