#include "pt4.h"
using namespace std;

void Solve()
{
	Task("TheTwo23");
	int n, last_digit = 0;
	bool result = true;
	pt >> n;
	while (n > 0)
	{
		int digit = n % 10;

		if (digit < last_digit)
		{
			result = false;
			break;
		}

		last_digit = digit;
		n /= 10;
	}
	pt << result;
}