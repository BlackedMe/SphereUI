#include "mainLoop.hpp"
#include "input.hpp"
#include "update.hpp"
#include "shader.hpp"
#include "program.hpp"
#include "renderer.hpp"
#include "panel.hpp"
#include "panelItem.hpp"
#include "glfwHandler.hpp"

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

  Panel *panel = new Panel(&glfwHwnd, &program, &renderer);
  panel->addButton();
  panel->addButton(SP_LEFT);
  panel->addButton(SP_BOTTOM);

  //game Loop
  while(!glfwWindowShouldClose(glfwHwnd.getWindow()))
  {
    panel->render();
  }
  glfwTerminate();
}
