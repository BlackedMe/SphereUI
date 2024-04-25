#include "clickBehavior.hpp"
#include <iostream>

void Clickable::click(){
  std::cout << "Button clicked!"; 
};

void NonClickable::click()
{
}
