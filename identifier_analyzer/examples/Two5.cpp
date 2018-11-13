#include "pt4.h"
using namespace std;

void Solve()
{
	Task("Two5");
	int a, b, result = 0;
	pt >> a >> b;

	int num = a > 0 ? a : 0;
	if (num % 4 != 0)
	{
		num += 4 - num % 4;
	}

	while (num <= b)
	{
		result += num;
		num += 4;
	}
	pt << result;
}