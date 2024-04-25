#include "panelComponent.hpp"
#include "renderable.hpp"
#include "glfwHandler.hpp"
#include "renderer.hpp"
#include "program.hpp"
class Panel : public Renderable{
public: 
  Panel(PanelComponent *panel, GLFWHandler *glfwHwnd, Program *program, Renderer *renderer);

  void render() override;
private:
  //dependencies
  PanelComponent *panel;
  GLFWHandler *glfwHwnd;
  Program *program; 
  Renderer *renderer;
};
