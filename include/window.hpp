#include "guiComponent.hpp"
#include <string>
class Window : GUIComponent{
public: 
  Window(const std::string &name);
  void render() override;
private:
  std::string name;
};
