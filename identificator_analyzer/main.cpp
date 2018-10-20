#include <iostream>
#include "file_reader.h"
#include "simple_parser.h"

int main()
{
	file_reader reader("example.txt");
	simple_parser parser;
	auto result = parser.parse_all(reader);
	for (const auto& it : result.get_all_words())
	{
		for (const auto& c : it.first)
		{
			std::cout << c;
		}
		std::cout << " " << it.second << std::endl;
	}
}