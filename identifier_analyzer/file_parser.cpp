#include "file_parser.h"
#include <fstream>
#include <sstream>
#include <string>

file_parser::file_parser(std::string file_name)
{
	parse_file(file_name);
}

void file_parser::add_words(std::set<std::string> words)
{
	for (auto& word : words)
	{
		if (dictionary.is_reserved_word(word))
		{
			add_reserved_word(word);
		}
		else
		{
			add_user_defined_word(word);
		}
	}
}

void file_parser::parse_file(std::string file_name)
{
	std::ifstream stream(file_name);

	std::string buffer;
	while (getline(stream, buffer))
	{
		parse_line(buffer);
	}
}

void file_parser::parse_line(std::string line)
{
	if (!line.empty() && line[0] == '#')
	{
		parse_preprocessor_directive(line);
		return;
	}
	std::istringstream stream(line);
	std::string buffer;
	while (stream >> buffer)
	{
		auto result = parser.parse_word(buffer);
		add_words(result);
	}
}

void file_parser::parse_preprocessor_directive(std::string line)
{
	std::istringstream stream(line);
	std::string buffer;
	stream >> buffer;
	if (buffer != "#define")
	{
		return;
	}
	while (stream >> buffer)
	{
		auto result = parser.parse_word(buffer);
		add_words(result);
	}
}