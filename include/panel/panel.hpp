#include "panelComponent.hpp"
#include "renderable.hpp"
#include "program.hpp"
#include "glfwHandler.hpp"
#include "input.hpp"
#include "renderer.hpp"
#include "widgets/widget.hpp"

struct PanelParameters{
  Alignment alignment = SP_TOP;
  float width = 0.2, height = 0.1;
  float padX = 0.0, padY = 0.0, borderX = 0.0, borderY = 0.0, marginX = 0.0, marginY = 0.0;
}; 
class Panel : public Renderable{
public: 
  Panel(const uint32_t SCR_WIDTH, const uint32_t SCR_HEIGHT, const std::string &name);

  void render() override;

  void initProgram(const char* vShaderSrc, const char* fShaderSrc);

  void addButton(const PanelParameters &params = PanelParameters());

  bool isAlive = true;
private:
  //dependencies
  PanelComponent *panel;
  GLFWHandler glfwHwnd;
  Program program; 
  InputHandler inputHandler;
  Renderer renderer;

  void additionLogic(Widget *widget, const PanelParameters &params);
};
