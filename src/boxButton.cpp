#include "shapes.hpp"
#include "button.hpp"
#include "guiComponent.hpp"
#include "boxButton.hpp"

BoxButton::BoxButton(const float width, const float height, GUIComponent *component) : width(width), height(height), Button(component) {};

void BoxButton::create()
{
  id = Shapes::genBox(width, height);
}

void BoxButton::listen()
{
  
}

void BoxButton::render()
{
  glBindVertexArray(id);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  component->render();
}

