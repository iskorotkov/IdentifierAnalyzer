#include "line_analyzer.h"
#include <vector>
#include <sstream>

void line_analyzer::parse_line(const std::string& line)
{
	std::istringstream line_stream(line);
	std::vector<std::string> words;
	std::string buffer;
	while (line_stream >> buffer)
	{
		words.emplace_back(buffer);
	}
}