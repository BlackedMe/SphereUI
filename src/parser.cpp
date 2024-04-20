#include <string>
#include <fstream>

std::string *parseFromFile(std::string path, bool flag)
{
  std::string *res = new std::string;
  std::ifstream file(path); 

  std::string cur;
  while(getline(file, cur))
  {
    *res += (cur + '\n');
  }
  return res;
}

const char* parseFromFile(std::string path)
{
  std::string *s = parseFromFile(path, 1);
  return s->c_str();
}
