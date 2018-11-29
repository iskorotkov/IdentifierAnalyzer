#include "char_utility.h"
#include "invalid_syntax_exception.h"
#include "file_parser.h"


size_t char_utility::find_string_literal_end(const std::string& line, size_t begin)
{
	while (begin < line.size())
	{
		if (is_quotation(line[begin]))
		{
			return begin;
		}
		++begin;
	}
	throw invalid_syntax_exception("There is no matching \" on the current line");
}


bool char_utility::is_quotation(char c)
{
	return c == '\'' || c == '\"';
}

bool char_utility::is_brace(char c)
{
	return c == '('
		|| c == ')'
		|| c == '<'
		|| c == '>'
		|| c == '['
		|| c == ']';
}

bool char_utility::is_operation_sign(char c)
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
