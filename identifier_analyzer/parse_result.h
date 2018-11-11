#pragma once
#include <map>

class parse_result
{
public:
	void add_used_identifier(std::string word) { ++used_identifiers[word]; }
	auto get_used_identifiers() const { return used_identifiers; }

private:
	std::map<std::string, int> used_identifiers;
};
