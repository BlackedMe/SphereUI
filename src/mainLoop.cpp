#include "mainLoop.hpp"
#include "input.hpp"
#include "update.hpp"
#include "shader.hpp"
#include "renderer.hpp"
#include "glfwHandler.hpp"
#include "GLFW/glfw3.h"

void Program::run()
{
  GLFWHandler glfwHwnd(1280, 800); 
  glfwHwnd.init();

  //renderer
  Renderer renderer;

  //shader
  Shader shader;
  shader.init("../assets/shader/vShader.glsl", "../assets/shader/fShader.glsl", glfwHwnd.aspectRatio);

  //game Loop
  while(!glfwWindowShouldClose(glfwHwnd.getWindow()))
  {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);  
    
    InputHandler::processInput(); 

    UpdateHandler::update();

    shader.useProgram();

    renderer.render(glfwHwnd);    
  }
  glfwTerminate();
}
