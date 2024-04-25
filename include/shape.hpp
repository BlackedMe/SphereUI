#include "program.hpp"
#include "renderable.hpp"
#include "clickBehavior.hpp"
#include <glad/glad.h>
class Shape : public Renderable{
public:
  Shape(Program *program);
protected:
  ClickBehavior *clickBehavior;
  //dependencies
  Program *program;
};

class Rectangle : public Shape{
public:
  //initalizes the rectangle
  Rectangle(float width, float height, Program *program);
  //renders the rectangle
  void render() override;
private:
  float width, height;
};
