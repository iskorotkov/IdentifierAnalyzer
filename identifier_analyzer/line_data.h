#pragma once
#include "data.h"

class line_data : data
{
public:
	bool ends_with_semicolon() const;
};
