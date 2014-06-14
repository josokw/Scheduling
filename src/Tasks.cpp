#include "Tasks.hpp"
#include "Math.hpp"

#include <algorithm>

using namespace std;

Tasks::Tasks()
	: _specs()
{
}

void Tasks::addSpecs(int c, int d, int p)
{
	cdp_t cdp {c, d, p};
	_specs.push_back(cdp);
	sort(begin(_specs), end(_specs), 
	     [](const cdp_t& s1, const cdp_t& s2) { return s1.p < s2.p; });
}

int Tasks::timeslice() const
{
	int timesl {0};
	for (const auto& t: _specs)
	{
		timesl = gcd(timesl, t.c);
	}
	return timesl;
}

int Tasks::minorframe() const
{
	int minorf {0};
	for (const auto& t: _specs)
	{
		minorf = gcd(minorf, t.p);
	}
	return minorf;
}

int Tasks::majorframe() const
{
	int majorf {1};
	for (const auto& t: _specs)
	{
		majorf = lcm(majorf, t.p);
	}
	return majorf;
}

