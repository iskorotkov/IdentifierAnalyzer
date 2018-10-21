#pragma once
#include <string>
#include "analyzer.h"
#include "line_data.h"
#include <vector>

class line_analyzer : analyzer<line_data>
{
public:
	line_data analyze(const std::string& source) override;

private:
	std::vector<std::string> words;

	void parse_line(const std::string& source);
};
