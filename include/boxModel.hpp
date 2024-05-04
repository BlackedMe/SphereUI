#pragma once
#include "dimension.hpp"
#include "glm/ext/vector_float2.hpp"
class BoxModel{
public:
  void setContent(float width, float height);
  void setPadding(float padX, float padY);
  void setBorder(float borderX, float borderY);
  void setMargin(float marginX, float marginY);

  const glm::vec2 &getContent();
  const glm::vec2 &getPadding();
  const glm::vec2 &getBorder();
  const glm::vec2 &getMargin();
  
private:
  Dimension content;
  Dimension padding;
  Dimension border;
  Dimension margin;
  glm::vec2 boxDimension;
};
