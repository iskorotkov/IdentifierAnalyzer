#include "word_parser.h"

std::map<std::string, int> word_parser::parse_word(const std::string& word) const
{
	std::map<std::string, int> result;

	std::string buffer;
	for (size_t i = 0, size = word.size(); i < size; ++i)
	{
		auto& c = word[i];
		if (buffer.empty() && filter.is_valid_first_character(c)
			|| !buffer.empty() && filter.is_valid_character(c))
		{
			buffer.push_back(c);
		}
		else if (filter.is_quotation(c))
		{
			i = word.find(c, i + 1);
		}
		else if (!filter.is_valid_character(c))
		{
			if (filter.is_valid_word(buffer))
			{
				++result[buffer];
			}
			buffer.clear();
		}
	}
	if (filter.is_valid_word(buffer))
	{
		++result[buffer];
	}

	return result;
}
