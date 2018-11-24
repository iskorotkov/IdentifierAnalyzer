#include "pt4.h"
using namespace std;

void Solve()
{
	Task("For29");
	int n;
	double a, b;
	pt >> n >> a >> b;
	double size = (b - a) / n;
	pt << size << a;
	double elem = a;
	for (int i = 0; i < n; ++i)
	{
		elem += size;
		pt << elem;
	}
}