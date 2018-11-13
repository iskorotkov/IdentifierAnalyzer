#include "pt4.h"
using namespace std;

void Solve()
{
	Task("Series35");
	int count_all = 0, k;
	pt >> k;
	for (int i = 0; i < k; ++i)
	{
		int count = 0;
		int num;
		pt >> num;
		while (num)
		{
			++count;
			++count_all;
			pt >> num;
		}
		pt << count;
	}
	pt << count_all;
}