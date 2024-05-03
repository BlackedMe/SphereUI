#include "mainLoop.hpp"
#include "input.hpp"
#include "update.hpp"
#include "shader.hpp"
#include "program.hpp"
#include "renderer.hpp"
#include "panel/panel.hpp"
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
  panel->addButton({.padX = 0.1, .borderX = 0.05, .borderY = 0.05});
  panel->addButton({.padY = 0.2});
  panel->addButton({.padY = 0.2});

  //game Loop
  while(!glfwWindowShouldClose(glfwHwnd.getWindow()))
  {
    panel->render();
  }
  glfwTerminate();
}
