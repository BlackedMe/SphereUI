#include "guiComponent.hpp"
class BaseGUI : public GUIComponent{
public:
  void create() override;
  void listen() override;
  void render() override;
};
