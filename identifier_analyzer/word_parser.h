#pragma once
#include <string>
#include <set>
#include "word_filter.h"

class word_parser
{
public:
	std::set<std::string> parse_word(const std::string& word) const;

private:
	word_filter filter;
};
