#include "pt4.h"
using namespace std;

int MaxElem(int* a, int n)
{
	if (n == 1)
	{
		return a[0];
	}
	else
	{
		int cur_value = a[n - 1];
		int rec_value = MaxElem(a, n - 1);
		return cur_value > rec_value ? cur_value : rec_value;
	}
}

void Solve()
{
	Task("Recur11");

	for (int i = 0; i < 3; ++i)
	{
		int n, *a;
		pt >> n;
		a = new int[n];
		for (int j = 0; j < n; ++j)
		{
			pt >> a[j];
		}
		pt << MaxElem(a, n);
	}
}