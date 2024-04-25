#include "guiComponent.hpp"
#include "glfwHandler.hpp"
#include "renderer.hpp"
#include "program.hpp"
#include <list>
class Window : public GUIComponent{
public: 
  Window(GLFWHandler *glfwHwnd, Program *program, Renderer *renderer);
  void render() override;
  void add(GUIComponent *component) override;
  void remove(GUIComponent *component) override;
private:
  std::list<GUIComponent *> children;
  
  //dependencies
  GLFWHandler *glfwHwnd;
  Program *program; 
  Renderer *renderer;
};
