#pragma once
#include <string>
#include "parse_result.h"
#include "reserved_words_dictionary.h"
#include "word_parser.h"

class file_parser
{
public:
	file_parser(std::string file_name);

	auto get_reserved_words() const
	{
		return reserved_words;
	}
	auto get_user_defined_words() const
	{
		return user_defined_words;
	}

private:
	parse_result reserved_words;
	parse_result user_defined_words;
	reserved_words_dictionary dictionary;
	word_parser parser;
	bool is_commented_out = false;

	void add_words(std::map<std::string, int> words);
	void add_reserved_word(std::string word, int amount)
	{
		reserved_words.add_used_identifier(word, amount);
	}
	void add_user_defined_word(std::string word, int amount)
	{
		user_defined_words.add_used_identifier(word, amount);
	}

	void parse_file(const std::string& file_name);
	void parse_line(std::string& line);
	void parse_preprocessor_directive(std::string line);
	void remove_singleline_comments(std::string& line);
	void remove_multiline_comment(std::string& line);
	void erase_content(std::string::iterator begin, std::string::iterator end) const;

	std::string::iterator find_string_literal_end(std::string::iterator begin, std::string::iterator end) const;
};
