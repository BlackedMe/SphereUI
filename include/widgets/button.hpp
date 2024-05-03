#include "widgets/widget.hpp"
class Button : public Widget{ 
public:
  Button(float width, float height, Shapes id, GLuint program);

  void updateRequired() override;
private:
  //dependencies
  
  bool isClicked();
};
