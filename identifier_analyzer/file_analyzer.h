#pragma once
#include "file_data.h"
#include "base_analyzer.h"

class file_analyzer : public base_analyzer
{
public:
	file_data analyze(std::string file_name);

private:
	std::vector<char> file_content;

	cchar_iter get_line_end(const cchar_iter start, const cchar_iter end);
	cchar_iter skip_file_header(const cchar_iter start, const cchar_iter end);
	file_data pass_to_analyze(const cchar_iter start, const cchar_iter end);
	bool is_blank_line(cchar_iter start, cchar_iter end);
};
