#include "boxModel.hpp"

void BoxModel::setContent(float width, float height)
{
  content.setDimension(width, height);
}

void BoxModel::setPadding(float padX, float padY)
{
  padding.setDimension(content.getWidth() + 2 * padX, content.getHeight() + 2 * padY);
}

void BoxModel::setBorder(float borderX, float borderY)
{
  border.setDimension(padding.getWidth() + 2 * borderX, padding.getHeight() + 2 * borderY);
}

void BoxModel::setMargin(float marginX, float marginY)
{
  margin.setDimension(border.getWidth() + 2 * marginX, border.getHeight() + 2 * marginY);
}

float BoxModel::getPaddingWidth()
{
  return padding.getWidth();
}

float BoxModel::getPaddingHeight()
{
  return padding.getHeight();
}

float BoxModel::getBorderWidth()
{
  return border.getWidth();
}

float BoxModel::getBorderHeight()
{
  return border.getHeight();
}

float BoxModel::getBoxWidth()
{
  return margin.getWidth();
}

float BoxModel::getBoxHeight()
{
  return margin.getHeight();
}

