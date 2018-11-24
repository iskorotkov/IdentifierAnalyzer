#include "pt4.h"
using namespace std;

void ShiftLeft3(double& a, double& b, double& c)
{
	double temp = a;
	a = b;
	b = c;
	c = temp;
}

void Solve()
{
	Task("Proc15");

	double a, b, c;

	pt >> a >> b >> c;
	ShiftLeft3(a, b, c);
	pt << a << b << c;

	pt >> a >> b >> c;
	ShiftLeft3(a, b, c);
	pt << a << b << c;
}