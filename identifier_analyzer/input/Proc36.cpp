#include "pt4.h"
using namespace std;

int Fib(int n)
{
	int* numbers = new int[n];
	numbers[0] = 1;
	numbers[1] = 1;
	for (int i = 2; i < n; ++i)
	{
		numbers[i] = numbers[i - 1] + numbers[i - 2];
	}
	return numbers[n - 1];
}

void Solve()
{
	Task("Proc36");

	for (int i = 0; i < 5; ++i)
	{
		int n;
		pt >> n;
		pt << Fib(n);
	}
}