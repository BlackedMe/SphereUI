#pragma once
class Dimension{
public:
  Dimension();
  Dimension(float width, float height);
  float getWidth();
  float getHeight();
  void setDimension(float width, float height);
private:
  float width = 0, height = 0;
};
