#pragma once
#include "base_code_analyzer.h"
#include "expression_data.h"

class expression_analyzer :
	public base_code_analyzer<expression_data>
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

	expression_analyzer(expression_type type) : type(type) {}

private:
	expression_type type;
	c_iter start;
	c_iter end;

	void analyze_variable_introduction();
	void analyze_assignment();
	void analyze_function_call();
	void analyze_template_instantiation();
	void analyze_arithmetic_expression();
};
