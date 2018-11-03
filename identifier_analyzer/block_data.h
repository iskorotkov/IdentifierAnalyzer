#pragma once
#include "data.h"
#include "line_data.h"

class block_data : public data
{
public:
	void add_line_data(const line_data& data);
};
