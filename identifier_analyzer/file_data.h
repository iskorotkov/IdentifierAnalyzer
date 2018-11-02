#pragma once
#include "data.h"
#include "block_data.h"

class file_data : public data
{
public:
	void add_block_data(const block_data data);
};
