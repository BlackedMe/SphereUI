#include "panel.hpp"
#include "panelComponent.hpp"

Panel::Panel(PanelComponent *panel, GLFWHandler *glfwHwnd, Program *program, Renderer *renderer) : panel(panel), glfwHwnd(glfwHwnd), program(program), renderer(renderer) {};

void Panel::render()
{
  glfwMakeContextCurrent(glfwHwnd->getWindow());

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);  
  
  glfwPollEvents();

  program->use();
  
  panel->render();

  renderer->render(*glfwHwnd);
}
