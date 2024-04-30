#include "boxModel.hpp"

void BoxModel::setContent(float width, float height)
{
  content.setDimension(width, height);
}

void BoxModel::setPadding(float padX, float padY)
{
  padding.setDimension(padX, padY);
  updateBoxDimension();
}

float BoxModel::getBoxWidth()
{
  return boxDimension.x;
}

float BoxModel::getBoxHeight()
{
  return boxDimension.y;
}

void BoxModel::updateBoxDimension()
{
  boxDimension.x = content.getWidth() + padding.getWidth() * 2;
  boxDimension.y = content.getHeight() + padding.getHeight() * 2;
}

