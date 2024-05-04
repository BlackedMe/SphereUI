#include "observer.hpp"
#include "widgets/widget.hpp"
class Button : public Widget, public Observer{ 
public:
  Button(float width, float height, Shapes id, GLuint program);

  void update(MouseButton1 *mouseButton1) override;
  void updateRequired() override;
private:
  //components
  bool isClicked = false;

  //dependencies
  MouseButton1 *mouseButton1;
};
