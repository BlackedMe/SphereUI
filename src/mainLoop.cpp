#include "mainLoop.hpp"
#include "input.hpp"
#include "update.hpp"
#include "shader.hpp"
#include "renderer.hpp"
#include "glfwHandler.hpp"
#include "shapes.hpp"
#include "guiComponent.hpp"
#include "boxButton.hpp"
#include "baseGui.hpp"
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
  

  GUIComponent *button = new BoxButton(0.5f, 0.5f, new BaseGUI);
  button->create();
  //game Loop
  while(!glfwWindowShouldClose(glfwHwnd.getWindow()))
  {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);  
    
    InputHandler::processInput(); 

    UpdateHandler::update();

    shader.useProgram();
    
    button->render();
    renderer.render(glfwHwnd);    
  }
  glfwTerminate();
}
