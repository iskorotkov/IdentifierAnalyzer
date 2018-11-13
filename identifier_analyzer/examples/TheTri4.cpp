#include "pt4.h"
#include <fstream>
using namespace std;

int calculate_length(const int& x1, const int& y1, const int& x2, const int& y2)
{
	const int delta_x = x1 - x2;
	const int delta_y = y1 - y2;
	return delta_x * delta_x + delta_y * delta_y;
}

int find_min_length(ifstream& input)
{
	int n, min_length = -1, index = 0;
	input >> n;
	for (int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2;
		input >> x1 >> y1 >> x2 >> y2;
		int length = calculate_length(x1, y1, x2, y2);
		if (length < min_length || min_length < 0)
		{
			min_length = length;
			index = i + 1;
		}
	}
	return index;
}

void Solve()
{
	Task("TheTri4");
	ifstream input("d.otr");
	pt << find_min_length(input);
	input.close();
}