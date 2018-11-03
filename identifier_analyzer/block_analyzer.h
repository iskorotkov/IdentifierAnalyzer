#pragma once
#include "block_data.h"
#include "base_analyzer.h"

class block_analyzer : public base_analyzer
{
public:
	block_data analyze(const cchar_iter start, const cchar_iter end);

private:
	block_data result;

	void analyze_line(const cchar_iter start, const cchar_iter end);
	bool is_member_declaration(const cchar_iter start, const cchar_iter end);
	void analyze_member_declaration(const cchar_iter start, const cchar_iter end);
};
