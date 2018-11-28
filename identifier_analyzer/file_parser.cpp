#include "file_parser.h"
#include <fstream>
#include <sstream>
#include <string>
#include "io_exception.h"

file_parser::file_parser(const std::string& filename)
{
	parse_file(filename);
}

void file_parser::add_words(const std::map<std::string, int>& words)
{
	for (auto& word : words)
	{
		if (dictionary.is_reserved_word(word.first))
		{
			add_reserved_word(word.first, word.second);
		}
		else
		{
			add_user_defined_word(word.first, word.second);
		}
	}
}

void file_parser::parse_file(const std::string& file_name)
{
	std::ifstream stream(file_name);
	if (stream.fail())
	{
		throw io_exception("There is no such file");
	}
	std::string buffer;
	while (getline(stream, buffer))
	{
		parse_line(buffer);
	}
}

void file_parser::parse_line(std::string& line)
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

void file_parser::parse_preprocessor_directive(const std::string& line)
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
			line.erase(it, end + 1);
			return;
		}
	}
}

void file_parser::remove_multiline_comment(std::string& line)
{
	auto commenting_start = 0;
	for (size_t i = 0; i < line.size() - 1; ++i)
	{
		if (line[i] == '"')
		{
			i = find_string_literal_end(line, i);
		}
		if (line[i] == '/' && line[i + 1] == '*' && !is_commented_out)
		{
			commenting_start = i;
			is_commented_out = true;
		}
		else if (line[i] == '*' && line[i + 1] == '/' && is_commented_out)
		{
			line.erase(commenting_start, i - commenting_start + 1);
			is_commented_out = false;
		}
	}
	if (is_commented_out)
	{
		line.erase(commenting_start);
	}
}

std::string::const_iterator file_parser::find_string_literal_end(std::string::const_iterator begin, std::string::const_iterator end) const
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

size_t file_parser::find_string_literal_end(const std::string& line, size_t begin) const
{
	++begin;
	while (begin < line.size())
	{
		if (line[begin] == '"')
		{
			return begin;
		}
		++begin;
	}
	throw std::exception("There is no matching \" on the current line");
}
