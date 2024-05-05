#include "panel/panel.hpp"
#include "panel/panelComponent.hpp"
#include "panel/panelContainer.hpp"
#include "panel/panelItem.hpp"
#include "widgets/button.hpp"

Panel::Panel(const uint32_t SCR_WIDTH, const uint32_t SCR_HEIGHT, const std::string &name) : glfwHwnd(SCR_WIDTH, SCR_HEIGHT){
  glfwHwnd.createWindow(name);
  inputHandler.setWindow(glfwHwnd.getWindow());
  panel = new PanelContainer(2.0, 2.0);
};

void Panel::render()
{
  static float currentTime = glfwGetTime();

  glfwMakeContextCurrent(glfwHwnd.getWindow());

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);  
  
  float dt = glfwGetTime() - currentTime;
  currentTime = glfwGetTime();

  inputHandler.processInput(dt);

  program.use();
  
  panel->render();

  renderer.render(glfwHwnd);
}

void Panel::initProgram(const char* vShaderSrc, const char* fShaderSrc)
{
  program.init(vShaderSrc, fShaderSrc, glfwHwnd.aspectRatio);
}

void Panel::addButton(const PanelParameters &params)
{
  Button *button = new Button(params.width, params.height, SP_RECTANGLE, program.get());
  inputHandler.mouseButton1.attach(button);
  inputHandler.mouse.attach(button);


  additionLogic(button, params);

  PanelItem *item = new PanelItem(button);

  panel->add(item, params.alignment); 
}

void Panel::additionLogic(Widget *widget, const PanelParameters &params)
{
  widget->geometry().setPadding(params.padX, params.padY);
  widget->geometry().setBorder(params.borderX, params.borderY);
  widget->geometry().setMargin(params.marginX, params.marginY);
}
