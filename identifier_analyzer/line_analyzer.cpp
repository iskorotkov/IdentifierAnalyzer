#include <vector>
#include "line_analyzer.h"
#include "line_data.h"
#include "data.h"
#include "char_utility.h"

line_data line_analyzer::analyze(const std::vector<char>& source)
{
	parse_line(source);
	choose_pattern();
	return result;
}

void line_analyzer::parse_line(const std::vector<char>& line)
{
	std::vector<char> buffer;
	for (const auto& c : line)
	{
		if (is_separator(c) || is_operator(c))
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

void line_analyzer::analyze_assignment(unsigned int end_index, unsigned int start_index)
{
	unsigned int index = start_index;
	while (index < end_index)
	{
		if (is_valid_identifier_first_letter(words.at(index)[0]))
		{
			result.add_used_variable(words.at(index));
		}
		else if (index > 0
			&& is_separator(words.at(index)[0])
			&& is_valid_identifier_first_letter(words.at(index - 1)[0]))
		{
			auto function_call_end = find_function_call_end(index);
			if (function_call_end > index + 1)
			{
				analyze_function_call(function_call_end, index);
				index = function_call_end + 1;
			}
		}
		++index;
	}
}

void line_analyzer::analyze_variable_introduction()
{
	unsigned int index = 1;
	bool first_found = false;

	// Analyze first identifier ("a" in "int a, b, c")
	while (index < words.size() && !first_found)
	{
		if (!is_valid_identifier_first_letter(words.at(index)[0]) &&
			is_valid_identifier_first_letter(words.at(index - 1)[0]))
		{
			auto next_separator = find_next_separator(index);
			if (next_separator > index + 1)
			{
				analyze_assignment(next_separator, index - 1);
			}
			else
			{
				result.add_used_variable(words.at(index - 1));
			}

			first_found = true;
		}
		++index;
	}

	// Analyze the rest of identifiers ("b" and "c" in "int a, b, c")
	while (index < words.size())
	{
		if (is_separator(words.at(index - 1)[0]) && is_valid_identifier_first_letter(words.at(index)[0]))
		{
			auto next_separator = find_next_separator(index);
			if (next_separator > index + 1)
			{
				analyze_assignment(next_separator, index);
			}
			else
			{
				result.add_used_variable(words.at(index));
			}
		}
		++index;
	}
}

unsigned int line_analyzer::find_next_separator(unsigned int start_index)
{
	while (!is_separator(words.at(start_index)[0]) && start_index < words.size())
	{
		++start_index;
	}
	return start_index;
}

unsigned int line_analyzer::find_function_call_end(unsigned int start_index)
{
	++start_index;
	unsigned int depth_level = 1;
	while (depth_level != 0)
	{
		if (is_closing_brace(get_first_letter(start_index)))
		{
			--depth_level;
		}
		else if (is_opening_brace(get_first_letter(start_index)))
		{
			++depth_level;
		}
		++start_index;
	}
	return start_index;
}

unsigned int line_analyzer::find_first_special_symbol(unsigned int start_index)
{
	while (start_index < words.size()
		&& !is_valid_identifier_first_letter(get_first_letter(start_index)))
	{
		++start_index;
	}
	return start_index;
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
	auto index = find_first_special_symbol(0);
	if (index == 1 && is_operator(get_first_letter(index)))
	{
		analyze_assignment(words.size());
	}
	else if (index == 1 && is_opening_brace(get_first_letter(index)))
	{
		analyze_function_call(words.size());
	}
	else
	{
		analyze_variable_introduction();
	}
}

void line_analyzer::analyze_function_call(unsigned int end_index, unsigned int start_index)
{
	unsigned int index = start_index;
	while (index < end_index)
	{
		if (is_valid_identifier_first_letter(words.at(index)[0]))
		{
			result.add_used_variable(words.at(index));
		}
		++index;
	}
}