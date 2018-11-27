#include <iostream>
#include <string>
#include "file_parser.h"
#include "parse_result_writer.h"

int main()
{
	const std::string input = "input.txt";
	const std::string output = "output.txt";

	file_parser parser(input);
	auto result = parser.get_user_defined_words();
	parse_result_writer writer;
	writer.write_result(result, output);
}
