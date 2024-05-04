#include "GLFW/glfw3.h"
#include "keyHandler.hpp"
#include "event.hpp"

class InputHandler{
public:
  void processInput();
private:
  //components
  Event *mouseButton1;

  //dependencies
  GLFWwindow *window;
};
