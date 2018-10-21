#include "line_data.h"

void line_data::add_used_variable(const std::string& name)
{
	++used_variables[name];
}