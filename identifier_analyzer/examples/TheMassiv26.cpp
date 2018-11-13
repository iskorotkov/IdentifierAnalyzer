#include "pt4.h"
using namespace std;

void Solve()
{
	Task("TheMassiv26");

	int n;
	pt >> n;
	int* a = new int[n];
	for (auto it = a, end = a + n; it < end; ++it)
	{
		pt >> *it;
	}

	int count = 0;
	for (auto it = a + n - 2, start = a; it >= start; --it)
	{
		if (*it > it[1])
		{
			pt << it - a;
			++count;
		}
	}
	pt << count;

	delete[] a;
}