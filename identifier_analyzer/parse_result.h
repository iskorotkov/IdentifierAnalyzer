#pragma once
#include <map>

class parse_result
{
public:
	void add_identifier(const std::string& word, int amount) { identifiers[word] += amount; }
	auto get_identifiers() const { return identifiers; }

private:
	std::map<std::string, int> identifiers;
};
