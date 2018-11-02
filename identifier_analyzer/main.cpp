#include <iostream>
#include "io_utility.h"
#include "file_analyzer.h"

int main()
{
	file_analyzer f;
	std::cout << f.analyze("example.txt").get_used_identifiers();
}