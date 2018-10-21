#include "line_analyzer.h"
#include <vector>
#include <sstream>
#include "line_data.h"
#include "data.h"

line_data line_analyzer::analyze(const std::string& source)
{
	parse_line(source);
	auto size = words.size();
	line_data result;
	return result;
}

void line_analyzer::parse_line(const std::string& line)
{
	std::istringstream line_stream(line);
	std::string buffer;
	while (line_stream >> buffer)
	{
		words.emplace_back(buffer);
	}
}