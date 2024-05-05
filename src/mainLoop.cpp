#include "mainLoop.hpp"
#include "panel/panel.hpp"
#include "glfwHandler.hpp"

void SphereUI::run()
{
  GLFWHandler::init();

  Panel *panel = new Panel(400, 400, "panel1");
  panel->initProgram("../assets/shader/vShader.glsl", "../assets/shader/fShader.glsl");

  panel->addButton({.padX = 0.1, .borderX = 0.05, .borderY = 0.05});
  panel->addButton({.padY = 0.2});
  panel->addButton({.padY = 0.2});

  //game Loop
  while(panel->isAlive)
  {
    panel->render();
  }
  glfwTerminate();
}
