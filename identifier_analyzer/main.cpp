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
		for (const auto& c : buffer)
		{
			source.emplace_back(c);
		}
	}
	block_analyzer a;
	auto i = a.analyze(source).get_used_identifiers();
	std::cout << i;
}