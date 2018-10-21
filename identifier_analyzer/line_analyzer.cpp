#include <vector>
#include "line_analyzer.h"
#include "line_data.h"
#include "data.h"
#include "char_utility.h"

line_data line_analyzer::analyze(const std::string& source)
{
	parse_line(source);
	choose_pattern();
	return result;
}

void line_analyzer::parse_line(const std::string& line)
{
	std::vector<char> buffer;
	for (const auto& c : line)
	{
		if (is_separator(c))
		{
			add_word(buffer);
			add_word(c);
			buffer.clear();
		}
		else if (is_whitespace(c))
		{
			add_word(buffer);
			buffer.clear();
		}
		else
		{
			buffer.emplace_back(c);
		}
	}
	add_word(buffer);
}

void line_analyzer::analyze_assignment()
{
	unsigned int index = 0;
	while (index < words.size())
	{
		if (is_valid_identifier_first_letter(words.at(index)[0]))
		{
			result.add_used_variable(words.at(index));
		}
		++index;
	}
}

void line_analyzer::analyze_variable_introduction()
{
	unsigned int index = 1;
	bool first_found = false;
	while (index < words.size() && !first_found)
	{
		if (is_separator(words.at(index)[0]))
		{
			if (index > 0)
			{
				first_found = true;
				result.add_used_variable(words.at(index - 1));
			}
		}
		++index;
	}
	while (index < words.size())
	{
		if (is_separator(words.at(index - 1)[0]) && is_valid_identifier_first_letter(words.at(index)[0]))
		{
			result.add_used_variable(words.at(index));
		}
		++index;
	}
}

void line_analyzer::add_word(const std::vector<char> v)
{
	if (v.cbegin() != v.cend())
	{
		words.emplace_back(v.cbegin(), v.cend());
	}
}

void line_analyzer::add_word(const char& c)
{
	words.emplace_back(std::string{ c });
}

void line_analyzer::choose_pattern()
{
	auto words_size = words.size();
	if (true) // debug purpose only
	{
		analyze_assignment();
	}
}