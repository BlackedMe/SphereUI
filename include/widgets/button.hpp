#include "widgets/widget.hpp"
#include "events/listener.hpp"
class Button : public Widget{ 
public:
  Button(float width, float height, Shapes id, GLuint program);

  void click() override;

  void update(MouseButton1 *mouseButton1) override;
private:
};
