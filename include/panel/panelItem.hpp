#include "panelComponent.hpp"
#include "widgets/widget.hpp"

class PanelItem : public PanelComponent{
public:
  PanelItem(Widget *widget);

  void add(PanelComponent *component, Alignment alignment) override; 
  void render() override;
  BoxModel &geometry() override;
  Transform &transform() override;
private:
  Widget *widget;
};
