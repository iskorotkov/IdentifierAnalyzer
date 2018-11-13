#include "pt4.h"
#include <climits>
using namespace std;

void Solve()
{
	Task("TheMassiv17");

	int n;
	pt >> n;
	int* a = new int[n];
	for (auto it = a, end = a + n; it < end; ++it)
	{
		pt >> *it;
	}

	int min = INT_MAX, min2 = INT_MAX;
	for (auto it = a, end = a + n; it < end; ++it)
	{
		if (*it == min)
		{
			continue;
		}
		if (*it < min)
		{
			min2 = min;
			min = *it;
		}
		else if (*it < min2)
		{
			min2 = *it;
		}
	}
	pt << min2 << min;

	delete[] a;
}