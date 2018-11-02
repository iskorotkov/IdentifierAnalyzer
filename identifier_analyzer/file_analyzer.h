#pragma once
#include "file_data.h"
#include "base_analyzer.h"

class file_analyzer : public base_analyzer
{
public:
	file_data analyze(std::string file_name);

	c_iter get_line_end(const c_iter start, const c_iter end);
	c_iter skip_comments_and_preprocessor_directives(const c_iter start, const c_iter end);
	file_data pass_to_analyze(const c_iter start, const c_iter end);

private:
	std::vector<char> file_content;
};
