#include "pt4.h"
using namespace std;

void Solve()
{
	Task("One32");

	double x;
	pt >> x;

	double a = 2 * x; // 2x, первое умножение
	double b = a * a; // 4x2, второе умножение
	double c = a - 1; // 2x - 1, первое сложение/вычитание
	double d = b + 1; // 4x2 + 1, второе сложение/вычитание
	double e = b * d; // 4x2 * (4x2 + 1), третье умножение
	double f = e + 1; // 4x2 * (4x2 + 1) + 1, третье сложение/вычитание
	double result = c * f; // (2x - 1) * (4x2 * (4x2 + 1) + 1), четвертое умножение

	pt << result;
}
