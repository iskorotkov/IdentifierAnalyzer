#include "word_filter.h"

bool word_filter::is_valid_word(std::string word) const
{
	bool valid_length = is_valid_length(word);
	bool valid_first_character = is_first_character_valid(word);
	if (!valid_length || !valid_first_character)
	{
		return false;
	}
	for (auto i = word.cbegin(); i != word.cend(); ++i)
	{
		if (!is_valid_character(*i))
		{
			return false;
		}
	}
	return true;
}

bool word_filter::is_first_character_valid(std::string word) const
{
	return !word.empty() && (is_letter(word[0]) || is_underscore(word[0]));
}

bool word_filter::is_valid_character(char c) const
{
	return is_letter(c) || is_digit(c) || is_underscore(c);
}

bool word_filter::is_valid_length(std::string word) const
{
	int size = word.size();
	return size > 0 && size <= 256;
}