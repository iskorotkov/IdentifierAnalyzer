#pragma once
#include "block_data.h"
#include "analyzer.h"

class block_analyzer : public analyzer<block_data>
{
public:
	block_data analyze(const std::vector<char>::const_iterator start, const std::vector<char>::const_iterator end) override;

private:
	void analyze_line(const std::vector<char>::const_iterator start, const std::vector<char>::const_iterator end);
};
