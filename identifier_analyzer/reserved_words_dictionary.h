#pragma once
#include <set>

class reserved_words_dictionary
{
public:
	bool is_reserved_word(std::string word) const;

private:
	const std::set<std::string> reserved_words = {
		"return",
		"for",
	};
};
