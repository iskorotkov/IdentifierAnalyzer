#pragma once
#include <map>
#include <string>

class data
{
public:
	inline auto get_identifiers() const { return identifiers; }

private:
	std::map<std::string, int> identifiers;
};
