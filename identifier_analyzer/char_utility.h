#pragma once
static class char_utility
{
public:
	static bool is_letter(char c);
	static bool is_digit(char c);
	static bool is_valid_identifier_first_letter(char c);
	static bool is_separator(char c);
	static bool is_whitespace(char c);
	static bool is_operation(char c);
};
