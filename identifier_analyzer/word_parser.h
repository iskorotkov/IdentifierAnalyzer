#pragma once
#include <string>
#include <map>
#include "word_filter.h"

class word_parser
{
public:
	std::map<std::string, int> parse_word(const std::string& word) const;

private:
	word_filter filter;
};
