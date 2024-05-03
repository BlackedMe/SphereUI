#include "panelComponent.hpp"
#include "widgets/widget.hpp"

class PanelItem : public PanelComponent{
public:
  PanelItem(Widget *widget);

  void add(PanelComponent *component, Alignment alignment) override; 
  void render() override;

  void setPos(const glm::vec2 &pos) override;
  const glm::vec2 &getPos() override;

  float getWidth() override;
  float getHeight() override;
  void setDimension(float width, float height) override;
private:
  Widget *widget;
};
