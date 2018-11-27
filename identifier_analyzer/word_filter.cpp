#include "word_filter.h"

bool word_filter::is_valid_word(const std::string& word) const
{
	bool valid_length = is_valid_length(word);
	bool valid_first_character = is_valid_first_character(word);
	if (!valid_length || !valid_first_character)
	{
		return false;
	}
	for (const char i : word)
	{
		if (!is_valid_character(i))
		{
			return false;
		}
	}
	return true;
}

bool word_filter::is_valid_first_character(const std::string& word) const
{
	return !word.empty() && is_valid_first_character(word[0]);
}

bool word_filter::is_valid_first_character(char c) const
{
	return is_letter(c) || is_underscore(c);
}

bool word_filter::is_valid_character(char c) const
{
	return is_letter(c) || is_digit(c) || is_underscore(c);
}

bool word_filter::is_separator(char c) const
{
	return c == ';'
		|| c == ','
		|| c == ':'
		|| is_brace(c)
		|| is_operation_sign(c);
}

bool word_filter::is_valid_length(std::string word) const
{
	int size = word.size();
	return size > 0 && size <= 256;
}

bool word_filter::is_brace(char c) const
{
	return c == '('
		|| c == ')'
		|| c == '<'
		|| c == '>'
		|| c == '['
		|| c == ']';
}

bool word_filter::is_operation_sign(char c) const
{
	return c == '+'
		|| c == '-'
		|| c == '*'
		|| c == '/'
		|| c == '='
		|| c == '^'
		|| c == '~'
		|| c == '!';
}