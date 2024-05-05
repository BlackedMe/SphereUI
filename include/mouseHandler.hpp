#include "events/event.hpp"
#include <glm/vec2.hpp>
#include <vector>
class Mouse : public Event{
public: 
  void attach(Listener *listener) override;

  void notify() override;

  const glm::dvec2 &getPos();
  void setPos(const glm::dvec2 &pos);
private:
  std::vector<Listener *> listeners;

  glm::dvec2 pos;
};
