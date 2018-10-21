#pragma once
#include <map>
#include <string>

class data
{
public:
	auto get_used_identifiers() const { return used_identifiers; }

protected:
	std::map<std::string, int> used_identifiers;
};
