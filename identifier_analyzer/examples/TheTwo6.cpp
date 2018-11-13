#include "pt4.h"
using namespace std;

void Solve()
{
	Task("TheTwo6");
	int n, last = 2, sum = 2;
	pt >> n;

	for (int i = 2; i <= n; ++i)
	{
		last = 2 * last + 1;
		sum += last;
	}
	pt << last << sum;
}