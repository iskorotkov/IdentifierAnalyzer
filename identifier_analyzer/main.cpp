#include <iostream>
#include "line_analyzer.h"
#include "line_data.h"
#include "io_utility.h"

int main()
{
	line_analyzer a;
	auto i = a.analyze(
		"int a = f(b, c), b = t(a, l);"
	).get_used_identifiers();
	std::cout << i;
}