#include <vector>
#include "line_analyzer.h"
#include "line_data.h"
#include "data.h"

line_data line_analyzer::analyze(const std::string& source)
{
	parse_line(source);
	choose_pattern();
	return result;
}

void line_analyzer::parse_line(const std::string& line)
{
}

void line_analyzer::choose_pattern()
{
	auto words_size = words.size();
	if (words_size >= 3)
	{
	}
}