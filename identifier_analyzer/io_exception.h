#pragma once
#include <exception>

class io_exception : std::exception
{
public:
	io_exception(char const* const message) : std::exception(message) {}
};
