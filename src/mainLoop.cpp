#include "mainLoop.hpp"
#include "input.hpp"
#include "update.hpp"
#include "shader.hpp"
#include "program.hpp"
#include "renderer.hpp"
#include "shape.hpp"
#include "window.hpp"
#include "windowItem.hpp"
#include "glfwHandler.hpp"
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
  // rectangle->setPos(glm::vec2(0.0, 1.0));

  GUIComponent* panel_1 = new Window(&glfwHwnd, &program, &renderer);
  GUIComponent* item_1 = new WindowItem(rectangle);
  panel_1->add(item_1);
  //game Loop
  while(!glfwWindowShouldClose(glfwHwnd.getWindow()))
  {
    panel_1->render();
  }
  glfwTerminate();
}
