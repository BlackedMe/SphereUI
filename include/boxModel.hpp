#pragma once
#include "dimension.hpp"
#include "glm/ext/vector_float2.hpp"
class BoxModel{
public:
  void setContent(float width, float height);
  void setPadding(float padX, float padY);
  // void setBorder(float borderX, float padY);
  // void setMargin(float padX, float );

  float getBoxWidth();
  float getBoxHeight();
private:
  Dimension content;
  Dimension padding;
  // Dimension border;
  // Dimension margin;
  glm::vec2 boxDimension;

  void updateBoxDimension();
};
