#include "pt4.h"
using namespace std;

bool is_palindrome(const int& original_num)
{
	int num = original_num;
	int reversed_num = 0;
	while (num > 0)
	{
		reversed_num *= 10;
		reversed_num += num % 10;
		num /= 10;
	}
	return reversed_num == original_num;
}

void Solve()
{
	Task("TheTri8");

	int a, b, counter = 0;
	pt >> a >> b;
	for (int i = a; i <= b; i++)
	{
		if (is_palindrome(i))
		{
			++counter;
			pt << i;
		}
	}
	if (counter == 0)
	{
		pt << "No solution";
	}
}