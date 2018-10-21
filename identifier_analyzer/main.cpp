#include <iostream>
#include "line_analyzer.h"
#include "line_data.h"
#include "io_utility.h"

int main()
{
	line_analyzer a;
	auto i = a.analyze(
		"int t = f(ab,cd), k = fr();"
	).get_used_identifiers();
	std::cout << i;
}