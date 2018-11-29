#pragma once
#include <exception>

/** Îרטבךא נאבמעû ס פאיכאלט */
class io_exception : std::exception
{
public:
	io_exception(const char* const message) : std::exception(message) {}
};
