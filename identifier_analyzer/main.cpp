#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "line_analyzer.h"
#include "line_data.h"
#include "block_analyzer.h"
#include "io_utility.h"

int main()
{
	std::ifstream input("example.txt");
	std::string buffer;
	std::vector<char> source;
	while (getline(input, buffer))
	{
		source.insert(source.cend(), buffer.begin(), buffer.end());
	}
	block_analyzer a;
	auto i = a.analyze(source.cbegin(), source.cend()).get_used_identifiers();
	std::cout << i;
}