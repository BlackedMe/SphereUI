#include "mainLoop.hpp"
#include "input.hpp"
#include "renderable.hpp"
#include "update.hpp"
#include "shader.hpp"
#include "program.hpp"
#include "renderer.hpp"
#include "shape.hpp"
#include "glfwHandler.hpp"
#include "GLFW/glfw3.h"

void SphereUI::run()
{
  GLFWHandler glfwHwnd(400, 400); 
  glfwHwnd.init();

  //renderer
  Renderer renderer;

  //program
  Program program; 
  program.init("../assets/shader/vShader.glsl", "../assets/shader/fShader.glsl", glfwHwnd.aspectRatio);

  Shape *rectangle = new Rectangle(1.0, 0.5, &program);
  rectangle->setPos(glm::vec2(0.0, 1.0));
  //game Loop
  while(!glfwWindowShouldClose(glfwHwnd.getWindow()))
  {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);  
    
    InputHandler::processInput(); 

    UpdateHandler::update();

    program.use();

    rectangle->render();
    renderer.render(glfwHwnd);    
  }
  glfwTerminate();
}
