#pragma once
#include <string>
#include "analyzer.h"

class line_analyzer : analyzer
{
public:

private:
	void parse_line(const std::string& source);
};
