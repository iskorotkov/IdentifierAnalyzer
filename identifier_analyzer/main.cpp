#include <iostream>
#include "line_analyzer.h"
#include "line_data.h"
#include "io_utility.h"

int main()
{
	line_analyzer a;
	auto i = a.analyze("int a, b = 10, c = 42, d = 0;").get_used_identifiers();
	auto w = a.get_words();
	std::cout << i;
}