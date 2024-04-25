#pragma once
class ClickBehavior{
public:
  virtual void click() = 0;
};

class Clickable : ClickBehavior{
public:
  void click() override;
};

class NonClickable : ClickBehavior{
public:
  void click() override;
};
