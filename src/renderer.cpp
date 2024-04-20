#include "renderer.hpp"
#include "glfwHandler.hpp"
#include "GLFW/glfw3.h"

void Renderer::render(GLFWHandler &hwnd)
{
  glfwSwapBuffers(hwnd.getWindow());
}
