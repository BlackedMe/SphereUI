#include "panel/panel.hpp"
#include "panel/panelComponent.hpp"
#include "panel/panelContainer.hpp"
#include "panel/panelItem.hpp"
#include "widgets/button.hpp"

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

void Panel::addButton(const PanelParameters &params)
{
  Widget *widget = new Button(params.width, params.height, SP_RECTANGLE, program->get());

  additionLogic(widget, params);

  PanelItem *item = new PanelItem(widget);

  panel->add(item, params.alignment); 
}

void Panel::additionLogic(Widget *widget, const PanelParameters &params)
{
  widget->setPadding(params.padX, params.padY);
  widget->setBorder(params.borderX, params.borderY);
  widget->setMargin(params.marginX, params.marginY);
}
