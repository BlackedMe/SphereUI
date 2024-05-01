#include "panelComponent.hpp"
#include "renderable.hpp"
#include "program.hpp"
#include "glfwHandler.hpp"
#include "renderer.hpp"
class Panel : public Renderable{
public: 
  Panel(GLFWHandler *glfwHwnd, Program *program, Renderer *renderer);

  void render() override;

  void addButton(Alignment alignment = SP_TOP, float width = 0.2, float height = 0.1);
private:
  //dependencies
  PanelComponent *panel;
  GLFWHandler *glfwHwnd;
  Program *program; 
  Renderer *renderer;
};
