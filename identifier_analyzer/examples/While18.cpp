#include "pt4.h"
using namespace std;

void Solve()
{
	Task("While18");
	int count = 0, sum = 0, n;
	pt >> n;
	while (n)
	{
		sum += n % 10;
		++count;
		n /= 10;
	}
	pt << count << sum;
}