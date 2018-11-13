#include "pt4.h"
#include <climits>
using namespace std;

void Solve()
{
	Task("TheMassiv18");

	int n;
	pt >> n;
	int* a = new int[n];
	for (int i = 0; i < n; ++i)
	{
		pt >> a[i];
	}

	int max1 = INT_MIN, max2 = INT_MIN;

	for (int* it = a; it < a + n; ++it)
	{
		if (*it > max2)
		{
			max1 = max2;
			max2 = *it;
		}
		else if (*it > max1 && *it != max2)
		{
			max1 = *it;
		}
	}
	pt << max1 << max2;
}