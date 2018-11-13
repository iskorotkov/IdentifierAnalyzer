#include "pt4.h"
using namespace std;

const int base = 9;

int convert(int num)
{
	int result = 0, order = 1;
	while (num)
	{
		result += (num % base) * order;
		order *= 10;
		num /= base;
	}
	return result;
}

void Solve()
{
	Task("Tri10");
	int num;
	do
	{
		pt >> num;
		pt << convert(num);
	} while (num);
}