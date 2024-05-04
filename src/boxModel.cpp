#include "boxModel.hpp"

void BoxModel::setContent(float width, float height)
{
  content.setDimension(width, height);
  setPadding(padding.getDimension().x, padding.getDimension().y);
}

void BoxModel::setPadding(float padX, float padY)
{
  padding.setDimension(content.getDimension().x + 2 * padX, content.getDimension().y + 2 * padY);
  setBorder(border.getDimension().x, border.getDimension().y);
}

void BoxModel::setBorder(float borderX, float borderY)
{
  border.setDimension(padding.getDimension().x + 2 * borderX, padding.getDimension().y + 2 * borderY);
  setMargin(margin.getDimension().x, margin.getDimension().y);
}

void BoxModel::setMargin(float marginX, float marginY)
{
  margin.setDimension(border.getDimension().x + 2 * marginX, border.getDimension().y + 2 * marginY);
}

const glm::vec2 &BoxModel::getContent()
{
  return content.getDimension();
}

const glm::vec2 &BoxModel::getPadding()
{
  return padding.getDimension();
}

const glm::vec2 &BoxModel::getBorder()
{
  return border.getDimension();
}

const glm::vec2 &BoxModel::getMargin()
{
  return margin.getDimension();
}
