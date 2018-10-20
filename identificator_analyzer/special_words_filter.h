#pragma once
#include <string>

class special_words_filter
{
public:
	special_words_filter() = delete;

	static bool is_special_word(std::string word);
};
