#include "renderable.hpp"
class GUIComponent : Renderable{
public:
  virtual void add() = 0;
  virtual void remove() = 0;
  virtual GUIComponent getChild() = 0;
};
