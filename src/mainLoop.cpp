#include "mainLoop.hpp"
#include "input.hpp"
#include "panelComponent.hpp"
#include "update.hpp"
#include "shader.hpp"
#include "program.hpp"
#include "renderer.hpp"
#include "panel.hpp"
#include "panelItem.hpp"
#include "glfwHandler.hpp"
#include "widget.hpp"
#include "panelComponent.hpp"
#include "panelContainer.hpp"

void SphereUI::run()
{
  GLFWHandler::init();

  GLFWHandler glfwHwnd(400, 400); 
  glfwHwnd.createWindow("program");
  //renderer
  Renderer renderer;

  //program
  Program program; 
  program.init("../assets/shader/vShader.glsl", "../assets/shader/fShader.glsl", glfwHwnd.aspectRatio);
  // Shape *shape = new Rectangle(0.5, 0.5);
  Widget *widget = new Widget(0.5, 0.2, program.get());
  widget->setPadding(0.0, 0.2);
  Widget *widget2 = new Widget(0.2, 0.2, program.get());
  widget2->setPadding(0.0, 0.2);
  Widget *widget3 = new Widget(0.2, 0.2, program.get());
  widget3->setPadding(0.0, 0.2);

  PanelComponent *component = new PanelContainer(2.0, 2.0);
  PanelComponent *item = new PanelItem(widget);
  PanelComponent *item2 = new PanelItem(widget2);
  PanelComponent *item3 = new PanelItem(widget3);
  component->add(item, SP_TOP);
  component->add(item2, SP_LEFT);

  Panel *panel = new Panel(component, &glfwHwnd, &program, &renderer);

  //game Loop
  while(!glfwWindowShouldClose(glfwHwnd.getWindow()))
  {
    panel->render();
  }
  glfwTerminate();
}
