#pragma once
#include <map>

class simple_parser_result
{
public:
	simple_parser_result(std::map<std::string, int> words_count) : words_count(words_count) {}

	inline auto get_words_count() const { return words_count; }
private:
	std::map<std::string, int> words_count;
};
