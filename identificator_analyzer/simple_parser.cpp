#include <map>
#include "simple_parser.h"
#include "simple_parser_result.h"
#include "file_reader.h"

void simple_parser::parse_all(file_reader reader)
{
	std::map<std::string, int> words_count;
	std::string buffer;
	while (reader >> buffer)
	{
		++words_count[buffer];
	}
	result = simple_parser_result(words_count);
}