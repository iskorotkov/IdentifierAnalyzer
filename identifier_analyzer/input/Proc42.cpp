#include "pt4.h"
using namespace std;

double Cos1(double x, double e)
{
	double result = 0;
	double i = 1;
	double elem = 1;
	while (abs(elem) > abs(e))
	{
		result += elem;
		elem *= -x * x / (i*i + i);
		i += 2;
	}
	return result;
}

void Solve()
{
	Task("Proc42");
	double x;
	pt >> x;
	for (int i = 0; i < 6; ++i)
	{
		double e;
		pt >> e;
		pt << Cos1(x, e);
	}
}