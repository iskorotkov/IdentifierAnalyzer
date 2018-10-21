#pragma once
#include "data.h"
#include <set>
#include <map>
#include <string>

class line_data : data
{
public:
	bool get_end_with_semicolon() const { return ends_with_semicolon; }
	bool get_introduces_variable() const { return introduces_variable; }
	void set_ends_with_semicolon(bool value) { ends_with_semicolon = value; }
	void set_introduces_variable(bool value) { introduces_variable = value; }

	auto get_introduced_variables() const { return introduced_variables; }
	void add_introduced_variable(const std::string& name);

	auto get_used_variables() const { return used_variables; }
	void add_used_variable(const std::string& name);

private:
	bool ends_with_semicolon, introduces_variable;

	std::set<std::string> introduced_variables;
	std::map<std::string, int> used_variables;
};
