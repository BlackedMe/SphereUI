#include "button.hpp"
class BoxButton : public Button{
public:
  BoxButton(const float width, const float height, GUIComponent *component);
  void create() override;
  void listen() override;
  void render() override;
private:
  const float width, height;
};

