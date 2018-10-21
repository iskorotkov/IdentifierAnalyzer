#include "char_utility.h"

bool is_letter(char c)
{
	return c >= 'a' && c <= 'z'
		|| c >= 'A' && c <= 'Z';
}

bool is_digit(char c)
{
	return c >= '0' && c <= '9';
}

bool is_valid_identifier_first_letter(char c)
{
	return is_letter(c) || c == '_';
}

bool is_separator(char c)
{
	return c == '{'
		|| c == '}'
		|| c == '('
		|| c == ')'
		|| c == '['
		|| c == ']'
		|| c == ';'
		|| c == ',';
}

bool is_whitespace(char c)
{
	return c == ' ' || c == '\t';
}

bool is_operator(char c)
{
	return c == '='
		|| c == '+'
		|| c == '-'
		|| c == '*'
		|| c == '/'
		|| c == '|'
		|| c == '&'
		|| c == '^'
		|| c == '~';
}

bool is_opening_brace(char c)
{
	return c == '('
		|| c == '['
		|| c == '{';
}

bool is_closing_brace(char c)
{
	return c == ')'
		|| c == ']'
		|| c == '}';
}