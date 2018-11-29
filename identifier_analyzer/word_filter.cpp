#include "word_filter.h"
#include "char_utility.h"

bool word_filter::is_valid_word(const std::string& word) const
{
	bool valid_length = is_valid_length(word);
	bool valid_first_character = is_valid_first_character(word[0]);
	if (!valid_length || !valid_first_character)
	{
		return false;
	}
	for (size_t i = 1; i < word.size(); ++i)
	{
		if (!is_valid_character(word[i]))
		{
			return false;
		}
	}
	return true;
}

bool word_filter::is_valid_first_character(char c) const
{
	return char_utility::is_letter(c) || char_utility::is_underscore(c);
}

bool word_filter::is_valid_character(char c) const
{
	return char_utility::is_letter(c)
		|| char_utility::is_digit(c)
		|| char_utility::is_underscore(c);
}

bool word_filter::is_valid_length(std::string word) const
{
	int size = word.size();
	return size > 0 && size <= 256;
}
