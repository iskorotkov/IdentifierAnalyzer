#include <vector>
#include "block_analyzer.h"
#include "block_data.h"
#include "line_analyzer.h"

block_data block_analyzer::analyze(const std::vector<char>::const_iterator start, const std::vector<char>::const_iterator end)
{
	auto delimiter = start, it = start;
	while (it < end)
	{
		if (*it == '\n' && it > delimiter + 1)
		{
			analyze_line(delimiter, it);
			delimiter = it + 1;
		}
		++it;
	}
	if (delimiter != it)
	{
		analyze_line(delimiter, it);
	}
	return result;
}

void block_analyzer::analyze_line(const std::vector<char>::const_iterator start, const std::vector<char>::const_iterator end)
{
	line_analyzer an;
	auto line_result = an.analyze(start, end);
	result.add_line_data(line_result);
}