#include "pt4.h"
using namespace std;

void Solve()
{
	Task("Array43");
	int n, *array, count = 1;
	pt >> n;
	array = new int[n];
	for (int i = 0; i < n; ++i)
	{
		pt >> array[i];
	}
	for (int i = 0; i < n - 1; ++i)
	{
		if (array[i] != array[i + 1])
		{
			++count;
		}
	}
	pt << count;
}