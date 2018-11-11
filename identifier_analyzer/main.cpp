#include <iostream>
#include "file_parser.h"
#include "parse_result_writer.h"

int main()
{
	const auto input = "example.txt";
	const auto output = "output.txt";

	file_parser parser(input);
	auto result = parser.get_user_defined_words();
	parse_result_writer writer;
	writer.write_result(result, output);
}