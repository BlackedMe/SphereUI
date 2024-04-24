#include "guiComponent.hpp"
#include "shape.hpp"
class WindowItem : GUIComponent{
public:
  void render() override;
private:
  Shape *shape;
};
