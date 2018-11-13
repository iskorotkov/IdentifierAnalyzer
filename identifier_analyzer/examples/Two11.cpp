#include "pt4.h"
using namespace std;

void Solve()
{
	Task("Two11");
	int n, m = 1, fact = 1;
	pt >> n;
	while (fact < n)
	{
		++m;
		fact *= m;
	}
	pt << m;
}