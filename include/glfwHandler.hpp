#pragma once
#include "GLFW/glfw3.h"
#include <string>
class GLFWHandler{
public:
  GLFWHandler(const uint32_t SCR_WIDTH, const uint32_t SCR_HEIGHT);
  //initalizes glfw
  static void init();

  void createWindow(const std::string &name);
  //returns window
  GLFWwindow *getWindow(); 

  //screen dimension
  const uint32_t SCR_WIDTH, SCR_HEIGHT; 

  //aspect ratio of the screen
  const float aspectRatio;
private:
  GLFWwindow *window; 

  void initCallback();
};
