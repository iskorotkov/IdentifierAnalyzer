#include <vector>
#include "block_analyzer.h"
#include "block_data.h"
#include "line_analyzer.h"

block_data block_analyzer::analyze(const c_iter start, const c_iter end)
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

void block_analyzer::analyze_line(const c_iter start, const c_iter end)
{
	if (is_member_declaration(start, end))
	{
		analyze_member_declaration(start, end);
	}
	else
	{
		line_analyzer an;
		auto line_result = an.analyze(start, end);
		result.add_line_data(line_result);
	}
}

bool block_analyzer::is_member_declaration(const c_iter start, const c_iter end)
{
	// TODO: add member declaration analyzing
	// Probably should create separate class for this
	return false;
}

void block_analyzer::analyze_member_declaration(const c_iter start, const c_iter end)
{
	// TODO: add logic
}