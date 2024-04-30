#version 420 core
uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;
uniform vec4 color;
out vec4 a_color;
layout (location = 0) in vec2 pos;

void main()
{
  gl_Position = proj * view * model * vec4(pos, 0, 1);
  a_color = color;
}
