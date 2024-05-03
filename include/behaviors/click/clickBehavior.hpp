class ClickBehavior{
  virtual void click() = 0;
};

class Clickable : public ClickBehavior{
  void click() override;
};

class Unclickable : public ClickBehavior {
  void click() override;
};
