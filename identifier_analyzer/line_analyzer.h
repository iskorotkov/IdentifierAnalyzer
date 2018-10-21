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
	void analyze_function_call();
	void analyze_assignment();
	void analyze_variable_introduction();
	void add_word(const std::vector<char> v);
	void add_word(const char& c);
};
