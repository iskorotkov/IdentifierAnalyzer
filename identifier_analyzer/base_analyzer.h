#pragma once
#include <vector>

class base_analyzer
{
public:
	using char_iter = std::vector<char>::iterator;
	using cchar_iter = std::vector<char>::const_iterator;

	using string_iter = std::vector<std::string>::iterator;
	using cstring_iter = std::vector<std::string>::const_iterator;
};