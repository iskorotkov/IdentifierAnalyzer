#pragma once
#include <string>

class word_filter
{
public:
	bool is_valid_word(std::string word) const;

private:
	bool is_first_character_valid(std::string word) const;
	bool is_valid_character(char c) const;
	bool is_valid_length(std::string word) const;
	bool is_digit(char c) const { return c >= '0' && c <= '9'; }
	bool is_letter(char c) const { return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'; }
	bool is_underscore(char c) const { return c == '_'; }
};
