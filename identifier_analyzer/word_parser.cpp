#include "word_parser.h"

std::set<std::string> word_parser::parse_word(const std::string& word) const
{
	std::set<std::string> result;

	std::string buffer;
	bool ignore_next_word = false;
	for (auto c : word)
	{
		if (buffer.empty() && filter.is_valid_character(c)
			|| filter.is_valid_character(c))
		{
			buffer.push_back(c);
		}
		else if (filter.is_separator(c))
		{
			if (!ignore_next_word)
			{
				if (filter.is_valid_word(buffer))
				{
					result.emplace(buffer);
				}
				buffer.clear();
				ignore_next_word = false;
			}
		}
		else
		{
			ignore_next_word = true;
		}
	}
	if (!ignore_next_word && !buffer.empty() && filter.is_valid_word(buffer))
	{
		result.emplace(buffer);
	}

	return result;
}