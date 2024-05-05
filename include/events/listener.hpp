#pragma once
class MouseButton1;
class Mouse;

class Listener{
public:
  virtual void update(MouseButton1 *mouseButton1) {};
  virtual void update(Mouse *mouse) {};
};
