#pragma once
#include <string>
#include <vector>
#include "analyzer.h"
#include "line_data.h"

class line_analyzer : analyzer<line_data>
{
public:
	line_data analyze(const std::string& source) override;

	auto get_words() const { return words; }

private:
	std::vector<std::string> words;
	line_data result;

	void parse_line(const std::string& source);
	void choose_pattern();
	void analyze_function_call();
	void analyze_assignment();
	void analyze_variable_introduction();
};
