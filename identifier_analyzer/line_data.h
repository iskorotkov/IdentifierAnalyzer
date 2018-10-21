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
	auto get_used_variables() const { return used_variables; }

	void add_introduced_variable(std::string name) { introduced_variables.emplace(name); }
	void add_used_varible(std::string name) { introduced_variables.emplace(name); }

private:
	bool ends_with_semicolon, introduces_variable;

	std::set<std::string> introduced_variables;
	std::set<std::string> used_variables;
};
