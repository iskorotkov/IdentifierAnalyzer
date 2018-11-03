#include <fstream>
#include <vector>
#include <string>
#include "file_analyzer.h"
#include "io_exception.h"
#include "char_utility.h"
#include "block_analyzer.h"

file_data file_analyzer::analyze(std::string file_name)
{
	if (file_name.empty())
	{
		throw io_exception("File name is empty!");
	}
	std::ifstream input(file_name);
	std::string buffer;
	while (getline(input, buffer))
	{
		file_content.insert(file_content.cend(), buffer.begin(), buffer.end());
		file_content.emplace_back('\n');
	}
	auto start = skip_file_header(file_content.begin(), file_content.end());
	return pass_to_analyze(start + 1, file_content.cend());
}

base_analyzer::cchar_iter file_analyzer::skip_file_header(const cchar_iter start, const cchar_iter end)
{
	auto line_start = start;
	auto it = get_line_end(start, end);
	while (it < end
		&& (is_slash(*line_start) || is_hashtag(*line_start) || is_blank_line(line_start, it)))
	{
		line_start = it;
		it = get_line_end(it, end) + 1;
	}
	return line_start;
}

file_data file_analyzer::pass_to_analyze(const cchar_iter start, const cchar_iter end)
{
	block_analyzer b;
	auto r = b.analyze(start, end);
	file_data result;
	result.add_block_data(r);
	return result;
}

bool file_analyzer::is_blank_line(cchar_iter start, cchar_iter end)
{
	if (start + 1 >= end)
	{
		return true;
	}
	for (auto it = start; it < end; ++it)
	{
		if (!is_whitespace(*it) && *it != '\n')
		{
			return false;
		}
	}
	return true;
}

base_analyzer::cchar_iter file_analyzer::get_line_end(const cchar_iter start, const cchar_iter end)
{
	auto it = start;
	while (*it != '\n')
	{
		++it;
	}
	return it;
}