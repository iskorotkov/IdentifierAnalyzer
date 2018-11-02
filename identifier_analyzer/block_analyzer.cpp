#include <vector>
#include "block_analyzer.h"
#include "block_data.h"
#include "line_analyzer.h"

block_data block_analyzer::analyze(const std::vector<char>& source)
{
	unsigned int start_index = 0, end_index = 0;
	while (end_index < source.size())
	{
		if (source[end_index] == '\n')
		{
			analyze_line(source, start_index, end_index);
			start_index = end_index;
		}
		++end_index;
	}
	if (start_index != end_index)
	{
		analyze_line(source, start_index, end_index);
	}
	return result;
}

void block_analyzer::analyze_line(const std::vector<char> &source, unsigned int start_index, unsigned int end_index)
{
	line_analyzer an;
	auto line_result = an.analyze(std::vector<char>(source.cbegin() + start_index, source.cbegin() + end_index));
	result.add_line_data(line_result);
}