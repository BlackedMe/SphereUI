#include "input.hpp"
#include "GLFW/glfw3.h"
#include "events/listener.hpp"

InputHandler::InputHandler()
{
}

void InputHandler::setWindow(GLFWwindow *window)
{
  this->window = window;
}

void InputHandler::processInput(float dt)
{
  countdown -= dt;

  glfwPollEvents();

  if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) && countdown <= 0)
  {
    mouseButton1.notify();
    countdown = cooldown;
  }

  double xPos, yPos;
  glfwGetCursorPos(window, &xPos, &yPos);

  xPos = -1 + 2 * xPos/400;
  yPos = 1 - 2 * yPos/400;

  if(xPos != mouse.getPos().x || yPos != mouse.getPos().y)
  {
    mouse.setPos(glm::dvec2(xPos, yPos)); 
    mouse.notify();  
  }
}
