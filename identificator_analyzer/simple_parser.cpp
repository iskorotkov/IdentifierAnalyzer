#include <map>
#include "simple_parser.h"
#include "simple_parser_result.h"
#include "file_reader.h"

simple_parser_result simple_parser::parse_all(file_reader& reader)
{
	std::map<std::string, int> words_count;
	std::string buffer;
	while (reader.read_words_till_end(buffer))
	{
		++words_count[buffer];
	}
	return simple_parser_result(words_count);
}