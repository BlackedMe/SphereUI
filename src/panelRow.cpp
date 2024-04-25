#include "panelRow.hpp"

PanelRow::PanelRow() {};
void PanelRow::render()
{
  for(PanelComponent *n : children)
  {
    n->render();
  }
}

void PanelRow::add(PanelComponent *component)
{
  children.push_back(component);
}
