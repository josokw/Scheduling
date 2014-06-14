#ifndef TASKS_HPP
#define TASKS_HPP

#include <vector>

class Tasks
{
public:
  using cdp_t = struct
  {
    int c;
    int d;
    int p;
  };
  Tasks();
  virtual ~Tasks() = default;
  void addSpecs(int c, int d, int p);
  std::vector<cdp_t>& getSpecs()
  {
    return _specs;
  }
  const std::vector<cdp_t>& getSpecs() const
  {
    return _specs;
  }
  int timeslice() const;
  int minorframe() const;
  int majorframe() const;
private:
  std::vector<cdp_t> _specs;
};

#endif
