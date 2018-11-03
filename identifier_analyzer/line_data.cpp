#include "line_data.h"

void line_data::add_expression_data(const expression_data& data)
{
	for (const auto& it : data.get_used_identifiers())
	{
		used_identifiers[it.first] += it.second;
	}
}