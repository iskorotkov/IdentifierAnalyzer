#pragma once
#include "data.h"
#include <set>
#include <map>
#include <string>

class line_data : public data
{
public:

	void add_used_variable(const std::string& name) { ++used_identifiers[name]; }
};
