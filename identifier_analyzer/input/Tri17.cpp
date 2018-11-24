#include "pt4.h"
using namespace std;

int digit_sum(int n)
{
	int result = 0;
	while (n)
	{
		result += n % 10;
		n /= 10;
	}
	return result;
}

int digit_root(const int& n)
{
	int result = n;
	while (result > 9)
	{
		result = digit_sum(result);
	}
	return result;
}

void Solve()
{
	Task("Tri17");
	int n;
	pt >> n;
	pt << digit_root(n);
}