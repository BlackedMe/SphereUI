#include "window.hpp"
#include "GLFW/glfw3.h"

Window::Window(GLFWHandler *glfwHwnd, Program *program, Renderer *renderer) : glfwHwnd(glfwHwnd), program(program), renderer(renderer) {};

void Window::add(GUIComponent *component)
{
  children.push_back(component); 
}

void Window::remove(GUIComponent *component)
{
}

void Window::render()
{
  glfwMakeContextCurrent(glfwHwnd->getWindow());

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);  
  
  glfwPollEvents();

  program->use();

  for(GUIComponent *n : children)
  {
    n->render();
  }

  renderer->render(*glfwHwnd);    
}
