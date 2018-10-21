#pragma once
#include <string>
#include <vector>
#include "analyzer.h"
#include "line_data.h"

class line_analyzer : public analyzer<line_data>
{
public:
	line_data analyze(const std::vector<char>& source) override;

private:
	std::vector<std::string> words;

	void parse_line(const std::vector<char>& source);
	void choose_pattern();

	// TODO: end index, then start index. Misleading
	void analyze_function_call(unsigned int end_index, unsigned int start_index = 2);
	void analyze_assignment(unsigned int end_index, unsigned int start_index = 0);
	void analyze_variable_introduction();
	unsigned int find_next_separator(unsigned int start_index);
	unsigned int find_function_call_end(unsigned int start_index);
	unsigned int find_first_special_symbol(unsigned int start_index);
	void add_word(const std::vector<char> v);
	void add_word(const char& c);
	inline char get_first_letter(unsigned int index) { return words.at(index)[0]; }
};
