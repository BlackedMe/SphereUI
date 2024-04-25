#include "panelComponent.hpp"
#include <list>
class PanelRow : public PanelComponent{
public:
  PanelRow();
  void render() override;
  void add(PanelComponent *component) override;
private: 
  std::list<PanelComponent *> children;
  int capacity = 10;
};
