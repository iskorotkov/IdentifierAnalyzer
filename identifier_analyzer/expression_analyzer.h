#pragma once
#include "base_analyzer.h"
#include "expression_data.h"
#include <vector>

class expression_analyzer : public base_analyzer
{
public:
	// TODO: create classes for each expression type (instead of using one)
	enum class expression_type
	{
		variable_introduction,
		assignment,
		function_call,
		template_instantiation,
		arithmetic_expression
	};

	expression_analyzer(expression_type type, cstring_iter start, cstring_iter end) : type(type), start(start), end(end) {}

private:
	expression_type type;
	cstring_iter start;
	cstring_iter end;

	void analyze_variable_introduction();
	void analyze_assignment();
	void analyze_function_call();
	void analyze_template_instantiation();
	void analyze_arithmetic_expression();
};
