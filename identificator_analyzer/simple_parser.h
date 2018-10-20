#pragma once
#include "simple_parser_result.h"

class file_reader;

class simple_parser
{
public:
	simple_parser_result parse_all(file_reader& reader);
};
