#pragma once
#include <string>
#include <vector>
#include "base_analyzer.h"
#include "line_data.h"

class line_analyzer : public base_analyzer
{
public:
	line_data analyze(const cchar_iter start, const cchar_iter end);

private:
	std::vector<std::string> words;
	line_data result;

	void parse_line(const cchar_iter start, const cchar_iter end);
	void choose_pattern();
	bool is_line_valid();

	// TODO: end index, then start index. Misleading
	void analyze_function_call(unsigned int start_index, unsigned int end_index);
	void analyze_assignment(unsigned int start_index, unsigned int end_index);
	void analyze_variable_introduction();
	unsigned int find_next_separator(unsigned int start_index);
	unsigned int find_function_call_end(unsigned int start_index);
	unsigned int find_first_special_symbol(unsigned int start_index);
	void add_word(const std::vector<char> v);
	void add_word(const char& c);
	inline char get_first_letter(unsigned int index) { return words.at(index)[0]; }

	inline bool is_return_statement(std::string& word) { return word == "return"; }
	inline bool is_return_statement() { return words.at(0) == "return"; }
	inline bool is_using_directive() { return words.at(0) == "using"; }
	inline bool is_typedef() { return words.at(0) == "typedef"; }
};
