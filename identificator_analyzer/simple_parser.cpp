#include <map>
#include "simple_parser.h"
#include "simple_parser_result.h"
#include "file_reader.h"

simple_parser_result simple_parser::parse_all(file_reader& reader)
{
	std::map<std::string, int> all_words;
	std::string buffer;
	while (reader.read_words_till_end(buffer))
	{
		++all_words[buffer];
	}
	return simple_parser_result(all_words);
}