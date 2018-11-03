#pragma once
#include "data.h"
#include <set>
#include <map>
#include <string>
#include "expression_data.h"

class line_data : public data
{
public:
	void add_expression_data(const expression_data& data);

	// TODO: remove methods (expression analyzer should do all work)
	void add_used_variable(const std::string& name) { ++used_identifiers[name]; }
};
