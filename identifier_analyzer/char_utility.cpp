#include "char_utility.h"

bool char_utility::is_letter(char c)
{
	return c >= 'a' && c <= 'z'
		|| c >= 'A' && c <= 'Z';
}

bool char_utility::is_digit(char c)
{
	return c >= '0' && c <= '9';
}

bool char_utility::is_valid_identifier_first_letter(char c)
{
	return is_letter(c) || c == '_';
}

bool char_utility::is_separator(char c)
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

bool char_utility::is_whitespace(char c)
{
	return c == ' ' || c == '\t';
}

bool char_utility::is_operation(char c)
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