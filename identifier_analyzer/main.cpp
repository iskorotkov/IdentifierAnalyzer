#include <iostream>
#include "file_parser.h"
#include "parse_result_writer.h"

int main()
{
	std::string input = "input.txt";
	std::string output = "output.txt";

	std::string buffer;
	std::cout << "Input file (leave empty for default): ";
	std::cin >> buffer;
	if (!buffer.empty())
	{
		input = buffer;
		buffer.clear();
	}
	std::cout << "Output file (leave empty for default): ";
	std::cin >> buffer;
	if (!buffer.empty())
	{
		output = buffer;
	}

	file_parser parser(input);
	auto result = parser.get_user_defined_words();
	parse_result_writer writer;
	writer.write_result(result, output);
}