#include "mainLoop.hpp"
#include "input.hpp"
#include "update.hpp"
#include "shader.hpp"
#include "renderer.hpp"
#include "glfwHandler.hpp"
#include "widget.hpp"
#include "panelComponent.hpp"
#include "panelContainer.hpp"
#include "panelItem.hpp"
#include <iostream>

void Program::run()
{
  GLFWHandler glfwHwnd(400, 400); 
  glfwHwnd.init();

  //renderer
  Renderer renderer;

  //shader
  Shader shader;
  shader.init("../assets/shader/vShader.glsl", "../assets/shader/fShader.glsl", glfwHwnd.aspectRatio);
  
  // Shape *shape = new Rectangle(0.5, 0.5);
  Widget *widget = new Widget(0.5, 0.2, shader.getProgram());
  widget->setPadding(0.0, 0.2);
  Widget *widget2 = new Widget(0.2, 0.2, shader.getProgram());
  widget2->setPadding(0.0, 0.2);
  Widget *widget3 = new Widget(0.2, 0.2, shader.getProgram());
  widget3->setPadding(0.0, 0.2);

  PanelComponent *component = new PanelContainer(2.0, 2.0);
  PanelComponent *item = new PanelItem(widget);
  PanelComponent *item2 = new PanelItem(widget2);
  PanelComponent *item3 = new PanelItem(widget3);
  component->add(item, SP_TOP);
  component->add(item2, SP_RIGHT);

  //game Loop
  while(!glfwWindowShouldClose(glfwHwnd.getWindow()))
  {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);  
    
    InputHandler::processInput(); 

    UpdateHandler::update();

    shader.useProgram();

    component->render();

    renderer.render(glfwHwnd);    
  }
  glfwTerminate();
}
