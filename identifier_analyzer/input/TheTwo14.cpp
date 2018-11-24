#include "pt4.h"
using namespace std;

void Solve()
{
	Task("TheTwo14");

	int n;
	pt >> n;
	double result = 0.;
	for (int i = 5; i <= n; ++i)
	{
		double power = double(i);
		for (int j = 1; j < n; ++j)
		{
			power *= i;
		}
		result += 1 / power;
	}
	pt << result;
}