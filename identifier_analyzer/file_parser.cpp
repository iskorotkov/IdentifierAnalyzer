#include "file_parser.h"
#include <fstream>

file_parser::file_parser(std::string file_name)
{
	parse_file(file_name);
}

void file_parser::parse_file(std::string file_name)
{
	std::ifstream stream(file_name);

	std::string buffer;
	while (stream >> buffer)
	{
		if (!filter.is_valid_word(buffer))
		{
			continue;
		}
		if (dictionary.is_reserved_word(buffer))
		{
			add_reserved_word(buffer);
		}
		else
		{
			add_user_defined_word(buffer);
		}
	}
}