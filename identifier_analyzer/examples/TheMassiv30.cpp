#include "pt4.h"
using namespace std;

void Solve()
{
	Task("TheMassiv30");

	int n;
	pt >> n;
	int* a = new int[n];
	for (int i = 0; i < n; ++i)
	{
		pt >> a[i];
	}

	int count = 0;
	for (int* it = a + n - 2; it > a; --it)
	{
		if (*it > *(it - 1) && *it > *(it + 1))
		{
			pt << it - a;
			++count;
		}
	}
	pt << count;
}