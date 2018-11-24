#include "pt4.h"
using namespace std;

void fill_array(int* array, int n)
{
	for (int i = 0; i < n; ++i)
	{
		pt >> array[i];
	}
}

double count(int* array, int n, int k, int l)
{
	int result = 0;
	int amount = 0;
	int left, right;
	if (l > k)
	{
		left = k, right = l;
	}
	else
	{
		left = l, right = k;
	}
	for (int i = 0; i < left; ++i)
	{
		result += array[i];
		++amount;
	}
	for (int i = right + 1; i < n; ++i)
	{
		result += array[i];
		++amount;
	}
	return static_cast<double>(result) / amount;
}

void Solve()
{
	Task("Massiv5");

	int n, k, l;
	pt >> n >> k >> l;
	int* a = new int[n];
	fill_array(a, n);
	pt << count(a, n, k, l);
}