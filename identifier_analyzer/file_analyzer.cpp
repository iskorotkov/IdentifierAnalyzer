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
	auto start = skip_comments_and_preprocessor_directives(file_content.begin(), file_content.end());
	return pass_to_analyze(start + 1, file_content.cend());
}

std::vector<char>::const_iterator file_analyzer::skip_comments_and_preprocessor_directives(const std::vector<char>::const_iterator start, const std::vector<char>::const_iterator end)
{
	auto it = start;
	while (it < end && (is_slash(*it) || is_hashtag(*it)))
	{
		it = get_line_end(it, end) + 1;
	}
	return it;
}

file_data file_analyzer::pass_to_analyze(const std::vector<char>::const_iterator start, const std::vector<char>::const_iterator end)
{
	block_analyzer b;
	auto r = b.analyze(start, end);
	file_data result;
	result.add_block_data(r);
	return result;
}

std::vector<char>::const_iterator file_analyzer::get_line_end(const std::vector<char>::const_iterator start, const std::vector<char>::const_iterator end)
{
	auto it = start;
	while (*it != '\n')
	{
		++it;
	}
	return it;
}