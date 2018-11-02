#pragma once
#include "block_data.h"
#include "base_code_analyzer.h"

class block_analyzer : public base_code_analyzer<block_data>
{
public:
	block_data analyze(const c_iter start, const c_iter end) override;

private:
	void analyze_line(const c_iter start, const c_iter end);
	bool is_member_declaration(const c_iter start, const c_iter end);
	void analyze_member_declaration(const c_iter start, const c_iter end);
};
