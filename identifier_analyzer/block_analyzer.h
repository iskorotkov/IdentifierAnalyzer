#pragma once
#include "block_data.h"
#include "analyzer.h"

class block_analyzer : public analyzer<block_data>
{
	using c_iter = std::vector<char>::const_iterator;
public:
	block_data analyze(const c_iter start, const c_iter end) override;

private:
	void analyze_line(const c_iter start, const c_iter end);
	bool is_member_declaration(const c_iter start, const c_iter end);
	void analyze_member_declaration(const c_iter start, const c_iter end);
};
