#include "panelComponent.hpp"
#include "shape.hpp"
class PanelItem : public PanelComponent{
public:
  PanelItem(Shape *shape);
  void render() override;
private:
  Shape *shape;
};
