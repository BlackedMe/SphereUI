#include "glad/glad.h"
class Shader{
public:
  void init(const char* vShaderSrc, const char* fShaderSrc, float aspectRatio);
  void useProgram();
private:
  GLuint compileShader(GLenum type, const char* src);
  GLuint program;
};
