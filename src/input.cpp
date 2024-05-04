#include "input.hpp"
#include "GLFW/glfw3.h"

void InputHandler::processInput()
{
  glfwPollEvents();

  if(glfwGetKey(window, GLFW_MOUSE_BUTTON_1))
  {
    mouseButton1->notify();
  }
}
