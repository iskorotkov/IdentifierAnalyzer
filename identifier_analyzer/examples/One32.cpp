#include "pt4.h"
using namespace std;

void Solve()
{
	Task("One32");

	double x;
	pt >> x;

	double a = 2 * x; // 2x, ������ ���������
	double b = a * a; // 4x2, ������ ���������
	double c = a - 1; // 2x - 1, ������ ��������/���������
	double d = b + 1; // 4x2 + 1, ������ ��������/���������
	double e = b * d; // 4x2 * (4x2 + 1), ������ ���������
	double f = e + 1; // 4x2 * (4x2 + 1) + 1, ������ ��������/���������
	double result = c * f; // (2x - 1) * (4x2 * (4x2 + 1) + 1), ��������� ���������

	pt << result;
}
