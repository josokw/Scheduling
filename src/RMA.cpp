#include "Tasks.hpp"
#include "RMA.hpp" 

#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

RMA::RMA(Tasks& tasks)
  : _tasks(tasks)
  , _tasksDiagram()
{
}

void RMA::schedule()
{
  int i = 1;
  for (auto t: _tasks.getSpecs())
  {
    cout << "T" << i << "   " << t.c << " " << t.d << " " << t.p << endl;
    ++i;
  }
  cout << endl;
  if (isSchedulable())
  {
    cout << "Tasks are schedulable!" << endl;
  }
  else
  {
    cout << "Tasks are schedulable?" << endl;
  }
  
  cout << "Timeslice = " << _tasks.timeslice() << "  ";
  cout << "Minorframe = " << _tasks.minorframe() << "  ";
  cout << "Majorframe = " << _tasks.majorframe() << endl;
  render();
  cout << endl;
  
  vector<int> todo;
  for (const auto& t: _tasks.getSpecs())
  {
    todo.push_back(0);
  }
  
  int taskIndex = 0;
  int diagramIndex = 4;
  while (diagramIndex < _tasksDiagram[0].size())
  { 
    switch (_tasksDiagram[taskIndex][diagramIndex])
    {
      case '!':
        if (todo[taskIndex] > 0)
        {
          cerr << "-- Tasks NOT schedulable" << endl;
        }
        todo[taskIndex] = _tasks.getSpecs()[taskIndex].c;
        ++taskIndex;
        break;
      case ' ':
        ++taskIndex;
        break;
      case '.':
        if (todo[taskIndex] > 0)
        {
          _tasksDiagram[taskIndex][diagramIndex] = 'x';
          --todo[taskIndex];
          taskIndex = 0;
          ++diagramIndex;
        }
        else
        {
          ++taskIndex;
        }
        break;
      default:
        cerr << "UNKNOWN char in diagram" << endl;
    }
    if (taskIndex >= todo.size()) 
    {
      taskIndex = 0; 
      ++diagramIndex;
    }
  }
  for (const auto& d: _tasksDiagram)
  {
    cout << d << endl; 
  }
  cout << endl;
}

bool RMA::isSchedulable()
{
  double sum {0.0};
  double maxsum {0.0}; 
  int nTasks {_tasks.getSpecs().size()};
  for (auto t: _tasks.getSpecs())
  {
    sum += double(t.c) / t.p;
  }
  maxsum = nTasks * (pow(2.0, (1.0 / nTasks)) - 1);
  cout << "Sufficient schedulable? " << sum << " <= " << maxsum << endl;
  
  return sum <= maxsum;
}

void RMA::render()
{
  int index {1};
  for (const auto& t: _tasks.getSpecs())
  {
    string td ("T" + to_string(index) + "  !");
    for (int i = 1; i <= _tasks.majorframe() / _tasks.minorframe(); ++i)
    {
      //cout << t.d << "  " << i * _tasks.minorframe() << endl;
      td += string(_tasks.minorframe(), '.');
      if ((i * _tasks.minorframe()) % t.d == 0)
      {  
        td += "!";
      }
      else
      {
        td += " ";
      }
    }
    _tasksDiagram.push_back(td);
    ++index;
  }
}
