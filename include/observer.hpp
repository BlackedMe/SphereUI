#pragma once
class MouseButton1;

class Observer{
public:
  virtual void update(MouseButton1 *mouseButton1) = 0;
};
