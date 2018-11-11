#include "expression_analyzer.h"
#include "char_utility.h"

auto expression_analyzer::get_result()
{
	switch (type)
	{
	case expression_type::unknown:
		choose_pattern();
		break;
	case expression_type::variable_introduction:
		analyze_variable_introduction();
		break;
	case expression_type::assignment:
		analyze_assignment();
		break;
	case expression_type::function_call:
		analyze_function_call();
		break;
	case expression_type::template_instantiation:
		analyze_template_instantiation();
		break;
	case expression_type::arithmetic_expression:
		analyze_arithmetic_expression();
		break;
	default:
		throw std::logic_error("Unhandled expression type");
		break;
	}
	return result;
}

void expression_analyzer::choose_pattern()
{
	if (start >= end)
	{
		return;
	}
	for (auto it = start; it < end; ++it)
	{
		// TODO: use methods instead of several ==
		if (first_letter(it) == '('
			|| first_letter(it) == '{')
		{
			analyze_function_call();
		}
		else if (first_letter(it) == '<')
		{
			analyze_template_instantiation();
		}
		else if (true)
		{
		}
	}
}