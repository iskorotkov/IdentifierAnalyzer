#pragma once
#include <map>

class simple_parser_result
{
public:
	simple_parser_result(std::map<std::string, int> all_words);

	inline auto get_all_words() const { return all_words; }
	inline auto get_special_words() const { return special_words; }
	inline auto get_user_words() const { return user_words; }

private:
	std::map<std::string, int> all_words;
	std::map<std::string, int> special_words;
	std::map<std::string, int> user_words;
};
