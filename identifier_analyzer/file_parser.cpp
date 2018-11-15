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
	if (line.empty())
	{
		return;
	}
	if (!line.empty() && line[0] == '#')
	{
		parse_preprocessor_directive(line);
		return;
	}
	remove_singleline_comments(line);
	remove_multiline_comment(line);
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

void file_parser::remove_singleline_comments(std::string& line)
{
	for (auto it = line.cbegin(), end = line.cend() - 1; it < end; ++it)
	{
		if (*it == '/' && it[1] == '/')
		{
			line.erase(it, end);
			return;
		}
	}
}

void file_parser::remove_multiline_comment(std::string& line)
{
	auto commenting_start = line.begin();
	for (auto begin = line.begin(), end = line.end(); begin < end; ++begin)
	{
		if (*begin == '"')
		{
			begin = find_string_literal_end(begin, end);
		}
		else if (begin < end - 1)
		{
			/*
			TODO:
			Optimize performance

			1. Look for '/', only then for '*'
			*/
			if (*begin == '/' && begin[1] == '*' && !is_commented_out)
			{
				commenting_start = begin;
				is_commented_out = true;
			}
			else if (*begin == '*' && begin[1] == '/' && is_commented_out)
			{
				erase_content(commenting_start, begin + 2);
				is_commented_out = false;
			}
		}
	}
}

void file_parser::erase_content(std::string::iterator begin, std::string::iterator end) const
{
	while (begin < end)
	{
		*begin = ' ';
		++begin;
	}
}

std::string::iterator file_parser::find_string_literal_end(std::string::iterator begin, std::string::iterator end) const
{
	++begin;
	while (begin < end)
	{
		if (*begin == '"')
		{
			return begin;
		}
		++begin;
	}
	throw std::exception("There is no matching \" on the current line");
}