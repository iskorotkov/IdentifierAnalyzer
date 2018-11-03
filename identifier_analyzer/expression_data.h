#pragma once
#include "data.h"

class expression_data : public data
{
public:
	void add_used_variable(const std::string& name) { ++used_identifiers[name]; }
};
