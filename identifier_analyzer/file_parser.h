#pragma once
#include <string>
#include "parse_result.h"
#include "reserved_words_dictionary.h"
#include "word_filter.h"

class file_parser
{
public:
	file_parser(std::string file_name);

	auto get_reserved_words() const { return reserved_words; }
	auto get_user_defined_words() const { return user_defined_words; }

private:
	parse_result reserved_words;
	parse_result user_defined_words;
	reserved_words_dictionary dictionary;
	word_filter filter;

	void add_reserved_word(std::string word) { reserved_words.add_used_identifier(word); }
	void add_user_defined_word(std::string word) { user_defined_words.add_used_identifier(word); }
	void parse_file(std::string file_name);
};
