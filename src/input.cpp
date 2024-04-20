#include "input.hpp"
#include "GLFW/glfw3.h"

void InputHandler::processInput()
{
  glfwPollEvents();
}
