#pragma once
#include "listener.hpp"
class Event{
public:
  virtual void attach(Listener *listener) = 0;
  // virtual void detach(Observer *observer) = 0;
  virtual void notify() = 0;
};
