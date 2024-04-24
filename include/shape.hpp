#include "renderable.hpp"
#include "clickBehavior.hpp"
#include <glad/glad.h>
class Shape : public Renderable{
protected:
  ClickBehavior *clickBehavior;
};

class Rectangle : public Shape{
public:
  //initalizes the rectangle
  Rectangle(float width, float height);
  //renders the rectangle
  void render() override;
private:
  float width, height;
};
