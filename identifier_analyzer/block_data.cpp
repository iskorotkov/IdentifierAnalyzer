#include "block_data.h"

void block_data::add_line_data(const line_data& data)
{
	for (const auto& it : data.get_used_identifiers())
	{
		used_identifiers[it.first] += it.second;
	}
}