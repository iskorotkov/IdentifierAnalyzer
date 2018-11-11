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
		unknown,
		variable_introduction,
		assignment,
		function_call,
		template_instantiation,
		arithmetic_expression
	};

	expression_analyzer(expression_type type, cstring_iter start, cstring_iter end) : type(type), start(start), end(end) {}

	auto get_result();

private:
	const expression_type type;
	const cstring_iter start;
	const cstring_iter end;
	expression_data result;

	void choose_pattern();
	void analyze_variable_introduction();
	void analyze_assignment();
	void analyze_function_call();
	void analyze_template_instantiation();
	void analyze_arithmetic_expression();
	void analyze_loop_header_expression();

	inline char first_letter(cstring_iter word) { return word->at(0); }
};
