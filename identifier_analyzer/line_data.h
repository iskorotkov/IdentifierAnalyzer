#pragma once
#include "data.h"
#include <set>
#include <map>
#include <string>

class line_data : data
{
public:
	auto get_used_variables() const { return used_variables; }
	void add_used_variable(const std::string& name);

private:
	std::map<std::string, int> used_variables;
};
