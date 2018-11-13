#include "pt4.h"
using namespace std;

void Solve()
{
	Task("Two20");
	int n, max_digit = 0;
	pt >> n;
	while (n > 0)
	{
		int digit = n % 10;
		max_digit = digit > max_digit ? digit : max_digit;
		n /= 10;
	}
	pt << max_digit;
}