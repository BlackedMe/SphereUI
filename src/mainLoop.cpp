#include "mainLoop.hpp"
#include "input.hpp"
#include "panelComponent.hpp"
#include "update.hpp"
#include "shader.hpp"
#include "program.hpp"
#include "renderer.hpp"
#include "shape.hpp"
#include "panel.hpp"
#include "panelItem.hpp"
#include "panelRow.hpp"
#include "glfwHandler.hpp"
#include "shapes.hpp"
#include "GLFW/glfw3.h"

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

  Shape *rectangle = new Rectangle(0.2, 0.1, &program);
  Shape *rectangle2 = new Rectangle(0.4, 1.0, &program);
  
  PanelComponent* panelRow_1 = new PanelRow;
  PanelComponent* item_1 = new PanelItem(rectangle);
  panelRow_1->add(item_1);
  Panel *panel = new Panel(panelRow_1, &glfwHwnd, &program, &renderer);
  //game Loop
  while(!glfwWindowShouldClose(glfwHwnd.getWindow()))
  {
    panel->render();
  }
  glfwTerminate();
}
