#include "pt4.h"
#include <climits>
using namespace std;

int min_digit(int n)
{
	return n < 10 ? n : min(n % 10, min_digit(n / 10));
}

void Solve()
{
	Task("Reccur5");
	int n;
	pt >> n;
	pt << min_digit(n);
}