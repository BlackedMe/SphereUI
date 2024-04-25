#include "guiComponent.hpp"
#include "windowItem.hpp"
#include <list>

class PanelRow : GUIComponent{
public:
private:
  std::list<WindowItem> items;
  int capacity = 10;
};
