#include "pt4.h"
#include <fstream>
using namespace std;

bool contains_digit(int num, const int& digit)
{
	bool contains = false;
	while (num > 0 && !contains)
	{
		int current_digit = num % 10;
		if (current_digit == digit)
		{
			contains = true;
			break;
		}
		num /= 10;
	}
	return contains;
}

void Solve()
{
	Task("TextFile9");
	ofstream output("a.dat");
	int a, b, n;
	pt >> a >> b >> n;
	for (int i = a; i <= b; ++i)
	{
		if (i == n || contains_digit(i, n))
		{
			output << i << endl;
		}
	}
	output.close();
}