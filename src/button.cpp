#include "widgets/button.hpp"
#include "widgets/widget.hpp"

Button::Button(float width, float height, Shapes id, GLuint program) : Widget(width, height, id, program) {
  clickBehavior = new Clickable();
};

void Button::updateRequired()
{
   
}

void Button::update(MouseButton1 *mouseButton1)
{
  isClicked = mouseButton1->getClickStatus();
}
