#pragma once
#include <string>
#include <vector>
#include "analyzer.h"
#include "line_data.h"

class line_analyzer : public analyzer<line_data>
{
public:
	line_data analyze(const std::string& source) override;

private:
	std::vector<std::string> words;
	line_data result;

	void parse_line(const std::string& source);
	void choose_pattern();

	// TODO: end index, then start index. Misleading
	void analyze_function_call(unsigned int end_index, unsigned int start_index = 2);
	void analyze_assignment(unsigned int end_index, unsigned int start_index = 0);
	void analyze_variable_introduction();
	unsigned int find_next_separator(unsigned int start_index);
	void add_word(const std::vector<char> v);
	void add_word(const char& c);
};
