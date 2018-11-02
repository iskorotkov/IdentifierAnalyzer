#include "file_data.h"

void file_data::add_block_data(const block_data data)
{
	for (const auto& it : data.get_used_identifiers())
	{
		used_identifiers[it.first] += it.second;
	}
}