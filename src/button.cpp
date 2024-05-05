#include "widgets/button.hpp"
#include "widgets/widget.hpp"
#include "events/listener.hpp"
#include <iostream>

Button::Button(float width, float height, Shapes id, GLuint program) : Widget(width, height, id, program) {};

void Button::click()
{
  std::cout << "button clicked!" << '\n';
}

void Button::update(MouseButton1 *mouseButton1)
{
  if(isHovered)
  {
    click();
  }
}
