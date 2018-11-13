#include "pt4.h"
using namespace std;

int sum(int n)
{
	if (n > 0)
	{
		return n * (n + 1) + sum(n - 1);
	}
	else
	{
		return 0;
	}
}

void Solve()
{
	Task("Reccur12");
	int n;
	pt >> n;
	int s = sum(n);
	pt << s;
}