#include "panelComponent.hpp"
#include "renderable.hpp"
#include "program.hpp"
#include "glfwHandler.hpp"
#include "renderer.hpp"
#include "widget.hpp"

struct PanelParameters{
  Alignment alignment = SP_TOP;
  float width = 0.2, height = 0.1;
  float padX = 0.0, padY = 0.0, borderX = 0.0, borderY = 0.0, marginX = 0.0, marginY = 0.0;
}; 
class Panel : public Renderable{
public: 
  Panel(GLFWHandler *glfwHwnd, Program *program, Renderer *renderer);

  void render() override;

  void addButton(const PanelParameters &params = PanelParameters());
private:
  //dependencies
  PanelComponent *panel;
  GLFWHandler *glfwHwnd;
  Program *program; 
  Renderer *renderer;

  void commonLogic(Widget *widget, const PanelParameters &params);
};
