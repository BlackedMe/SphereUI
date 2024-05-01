#include "panel.hpp"
#include "panelComponent.hpp"
#include "panelContainer.hpp"
#include "panelItem.hpp"
#include "widget.hpp"

Panel::Panel(GLFWHandler *glfwHwnd, Program *program, Renderer *renderer) : glfwHwnd(glfwHwnd), program(program), renderer(renderer) {
  panel = new PanelContainer(2.0, 2.0);
};

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

void Panel::addButton(Alignment alignment, float width, float height)
{
  Widget *widget = new Widget(0.2, 0.1, SP_RECTANGLE, program->get());
  PanelItem *item = new PanelItem(widget);
  panel->add(item, alignment); 
}
