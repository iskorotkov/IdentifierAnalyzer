#include <iostream>
#include "line_analyzer.h"
#include "line_data.h"
#include "io_utility.h"

int main()
{
	line_analyzer a;
	auto i = a.analyze("f(a, b+c, d, 10, a, a*10)").get_used_identifiers();
	std::cout << i;
}