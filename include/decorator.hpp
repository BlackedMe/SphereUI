#include "shape.hpp"
class Decorator : public Shape{
public:
  Decorator(Shape *shape);
  void render() override;
protected:
  Shape *shape;
};

class Hover : public Decorator{
public:
  Hover(Shape *shape);
  void render() override;
};
