#include "GLFW/glfw3.h"
#include "keyHandler.hpp"
#include "mouseHandler.hpp"

class InputHandler{
public:
  InputHandler();

  void setWindow(GLFWwindow *window);

  void processInput(float dt);
private:
  float cooldown = 1, countdown = cooldown;
  //components
  MouseButton1 mouseButton1;
  Mouse mouse;

  //dependencies
  GLFWwindow *window;

  friend class Panel;
};
