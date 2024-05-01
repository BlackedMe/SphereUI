#include "widget.hpp"
#include "shape.hpp"
#include "uniform.hpp"
#include <glm/mat4x4.hpp>
#include <glm/ext.hpp>

Widget::Widget(float width, float height, Shapes id, GLuint program) {
  shape = Shape::create(id, width, height);

  bm = new BoxModel;
  setContent(width, height);

  transform = new Transform;
  this->program = program;
};

void Widget::render()
{
  glm::mat4 model(1.0f);
  model = glm::translate(model, glm::vec3(getPos(), 0.0));
  uniformMatrix4fv(program, "model", 1, GL_FALSE, &model[0][0]);

  glUniform4f(glGetUniformLocation(program, "color"), 1.0f, 0.0f, 0.0f, 1.0f);
  Shape *border = new Rectangle(bm->getBorderWidth(), bm->getBorderHeight());
  border->render();

  glUniform4f(glGetUniformLocation(program, "color"), 0.0f, 0.0f, 1.0f, 1.0f);
  Shape *padding = new Rectangle(bm->getPaddingWidth(), bm->getPaddingHeight());
  padding->render();

  glUniform4f(glGetUniformLocation(program, "color"), 1.0f, 1.0f, 1.0f, 1.0f);
  shape->render();
}

void Widget::setPos(const glm::vec2 &pos)
{
  transform->setPos(pos);
}

const glm::vec2 &Widget::getPos()
{
  return transform->getPos();
}

void Widget::setContent(float width, float height)
{
  bm->setContent(width, height);
}

void Widget::setPadding(float padX, float padY)
{
  bm->setPadding(padX, padY);
}

void Widget::setBorder(float borderX, float borderY)
{
  bm->setBorder(borderX, borderY);
}

void Widget::setMargin(float marginX, float marginY)
{
  bm->setMargin(marginX, marginY);
}

float Widget::getBoxWidth()
{
  return bm->getBoxWidth();
}

float Widget::getBoxHeight()
{
  return bm->getBoxHeight();
}
