#pragma once
#include "file_data.h"

class file_analyzer
{
public:
	file_data analyze(std::string file_name);

	std::vector<char>::const_iterator get_line_end(const std::vector<char>::const_iterator start, const std::vector<char>::const_iterator end);
	std::vector<char>::const_iterator skip_comments_and_preprocessor_directives(const std::vector<char>::const_iterator start, const std::vector<char>::const_iterator end);
	file_data pass_to_analyze(const std::vector<char>::const_iterator start, const std::vector<char>::const_iterator end);

private:
	std::vector<char> file_content;
};
