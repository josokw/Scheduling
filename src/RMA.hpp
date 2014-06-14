#ifndef RMA_HPP
#define RMA_HPP

#include <string>
#include <vector>

class Tasks;

class RMA
{
public:
	RMA(Tasks& tasks);
	virtual ~RMA() = default;	
	void schedule();
private:
	Tasks& _tasks;
	std::vector<std::string> _tasksDiagram;
	bool isSchedulable();
	void render();
};

#endif
