#include "event.hpp"
#include "observer.hpp"
#include <vector>

class MouseButton1 : public Event{
public:
  void attach(Observer *observer) override;
  // void detach(Observer *observer) override;
  void notify() override;

  std::vector<Observer *> observers;
  
  bool getClickStatus();
private:
  bool isClicked = false;
};
