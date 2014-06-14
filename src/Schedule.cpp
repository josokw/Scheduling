#include <iostream>

#include "AppInfo.hpp"
#include "RMA.hpp"
#include "Tasks.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	cout << "---- " << APPNAME_VERSION << " started" << endl << endl;
	
	{
		Tasks tasks;
		tasks.addSpecs(1, 5, 5);
		tasks.addSpecs(5, 15, 15);
		tasks.addSpecs(2, 10, 10);
		RMA rma(tasks);
		rma.schedule();
	}
	{
		Tasks tasks;
		tasks.addSpecs(1, 5, 5);
		tasks.addSpecs(8, 15, 15);
		tasks.addSpecs(2, 10, 10);
		RMA rma(tasks);
		rma.schedule();
	}
	{
		Tasks tasks;
		tasks.addSpecs(32, 64, 64);
		tasks.addSpecs(8, 32, 32);
		tasks.addSpecs(4, 16, 16);
		RMA rma(tasks);
		rma.schedule();
	}
	
	cout << "---- ended" << endl << endl;

	return 0;
}
