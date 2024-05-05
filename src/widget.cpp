#include "widgets/widget.hpp"
#include "aabb.hpp"
#include "shape.hpp"
#include "uniform.hpp"
#include "collision.hpp"
#include "mouseHandler.hpp"
#include <glm/mat4x4.hpp>
#include <glm/ext.hpp>

Widget::Widget(float width, float height, Shapes id, GLuint program) {
  shape = Shape::create(id, width, height);

  bm.setContent(width, height);

  this->program = program;
};

void Widget::render()
{
  glm::mat4 model(1.0f);
  model = glm::translate(model, glm::vec3(transformation.getPos(), 0.0));
  uniformMatrix4fv(program, "model", 1, GL_FALSE, &model[0][0]);

  // glUniform4f(glGetUniformLocation(program, "color"), 1.0f, 0.0f, 0.0f, 1.0f);
  // Shape *border = new Rectangle(bm.getBorder());
  // border->render();

  // glUniform4f(glGetUniformLocation(program, "color"), 0.0f, 0.0f, 1.0f, 1.0f);
  // Shape *padding = new Rectangle(bm.getPadding());
  // padding->render();

  glUniform4f(glGetUniformLocation(program, "color"), 1.0f, 1.0f, 1.0f, 1.0f);
  shape->render();
}


BoxModel &Widget::geometry()
{
  return bm;
}

Transform &Widget::transform()
{
  return transformation;
}

void Widget::update(Mouse *mouse)
{
  AABB aabb;
  aabb.min = transformation.getPos() - bm.getContent() / glm::vec2(2.0);
  aabb.max = transformation.getPos() + bm.getContent() / glm::vec2(2.0);

  if(intersect(aabb, mouse->getPos()))
  {
    isHovered = true;
  }
  else isHovered = false;
}
