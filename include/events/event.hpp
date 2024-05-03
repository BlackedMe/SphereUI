class Event{
public:
  virtual void addListener() = 0;
  virtual void removeListener() = 0;
  virtual void notifyListener() = 0;
};
