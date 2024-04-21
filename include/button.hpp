#pragma once
#include "guiDecorator.hpp"
#include <glad/glad.h>

class Button : public GUIDecorator{
public:
  Button(GUIComponent* component);
  
  void render() override = 0;
protected:
  GLuint id;
};
