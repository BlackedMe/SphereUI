#include "guiComponent.hpp"
#include "shape.hpp"
class WindowItem : public GUIComponent{
public:
  WindowItem(Shape *shape);
  void render() override;
private:
  Shape *shape;
};
