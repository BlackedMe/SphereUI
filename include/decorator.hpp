#include "shape.hpp"
class Decorator : Shape{
public:
  void render() override;
protected:
  Shape *shape;
};

class Hover : Decorator{
public:
  void render() override;
};
