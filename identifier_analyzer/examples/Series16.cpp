#include "pt4.h"
using namespace std;

void Solve()
{
	Task("Series16");

	int result = 0, k, num, i = 1;
	pt >> k >> num;
	while (num)
	{
		if (num > k)
		{
			result = i;
		}
		pt >> num;
		++i;
	}
	pt << result;
}