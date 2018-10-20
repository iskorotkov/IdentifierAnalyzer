#pragma once
#include "simple_parser_result.h"

class file_reader;

class simple_parser
{
public:
	void parse_all(file_reader reader);
	inline simple_parser_result get_result() const { return result; }

private:
	simple_parser_result result;
};
