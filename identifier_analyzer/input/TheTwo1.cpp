#include "pt4.h"
#include <assert.h>
using namespace std;

void Solve()
{
	Task("TheTwo1");
	int n, sum1 = 0, sum2 = 0, sum3 = 0;
	pt >> n;

	// For
	for (int i = 1; i <= n; ++i)
	{
		sum1 += 11 * i;
	}
	// While
	int j = n;
	while (j > 0)
	{
		sum2 += 11 * j;
		--j;
	}
	// Do .. While
	int k = 0;
	do
	{
		sum3 += 11 * k;
		++k;
	} while (k <= n);

	assert(sum1 == sum2);
	assert(sum2 == sum3);

	pt << sum1;
}