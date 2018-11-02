#pragma once
#include "block_data.h"
#include "analyzer.h"

class block_analyzer : public analyzer<block_data>
{
public:
	block_data analyze(const std::vector<char>& source) override;

private:
	void analyze_line(const std::vector<char> &source, unsigned int start_index, unsigned int end_index);
};
