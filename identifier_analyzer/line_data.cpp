#include "line_data.h"

void line_data::add_introduced_variable(const std::string& name)
{
	introduced_variables.emplace(name);
	add_used_variable(name);
}

void line_data::add_used_variable(const std::string& name)
{
	++used_variables[name];
}