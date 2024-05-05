#include "events/event.hpp"
#include "events/listener.hpp"
#include <vector>

class MouseButton1 : public Event{
public:
  void attach(Listener *listener) override;
  // void detach(Observer *observer) override;
  void notify() override;

  std::vector<Listener *> listeners;
  
  bool getClickStatus();
private:
  bool isClicked = false;
};
