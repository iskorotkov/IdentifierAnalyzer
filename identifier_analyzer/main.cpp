#include <iostream>
#include "line_analyzer.h"
#include "line_data.h"
#include "io_utility.h"

int main()
{
	line_analyzer a;
	auto d = a.analyze("int a, b = 0");
	std::cout << d.get_used_variables();
}