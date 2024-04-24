#include "mainLoop.hpp"
#include "input.hpp"
#include "renderable.hpp"
#include "update.hpp"
#include "shader.hpp"
#include "renderer.hpp"
#include "shape.hpp"
#include "glfwHandler.hpp"
#include "GLFW/glfw3.h"

void Program::run()
{
  GLFWHandler glfwHwnd(400, 400); 
  glfwHwnd.init();

  //renderer
  Renderer renderer;

  //shader
  Shader shader;
  shader.init("../assets/shader/vShader.glsl", "../assets/shader/fShader.glsl", glfwHwnd.aspectRatio);

  Renderable::setProgram(shader.getProgram());
  Shape *rectangle = new Rectangle(1.0, 0.5);
  rectangle->setPos(glm::vec2(0.0f, 1.0f));

  //game Loop
  while(!glfwWindowShouldClose(glfwHwnd.getWindow()))
  {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);  
    
    InputHandler::processInput(); 

    UpdateHandler::update();

    shader.useProgram();

    rectangle->render();
    renderer.render(glfwHwnd);    
  }
  glfwTerminate();
}
