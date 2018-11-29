#pragma once
#include <exception>

class invalid_syntax_exception : std::exception
{
public:
	invalid_syntax_exception(const char* const message) : std::exception(message) {}
};
