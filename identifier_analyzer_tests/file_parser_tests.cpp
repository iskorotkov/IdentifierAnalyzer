#include "CppUnitTest.h"
#include <map>
#include <string>
#include "../identifier_analyzer/reserved_words_dictionary.cpp"
#include "../identifier_analyzer/word_parser.cpp"
#include "../identifier_analyzer/file_parser.cpp"
#include "../identifier_analyzer/word_filter.cpp"
#include "../identifier_analyzer/char_utility.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

const std::string path_to_folder = "D:/Projects/identifier_analyzer/identifier_analyzer_tests/examples/";
const std::string file_extension = ".txt";

auto get_parsed_result(std::string full_function_name)
{
	full_function_name.erase(0, full_function_name.rfind(':') + 1);
	file_parser parser(path_to_folder + full_function_name + file_extension);
	return parser.get_user_defined_words();
}

namespace file_parser_tests {
	TEST_CLASS(single_expression)
	{
	public:

		TEST_METHOD(assignment)
		{
			std::map<std::string, int> result =
			{
				{ "a", 1 },
				{ "b", 1 },
				{ "c", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(assignment_with_initializer_list)
		{
			std::map<std::string, int> result =
			{
				{ "s", 1 },
				{ "e", 1 },
				{ "string", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(multiple_variable_initialization)
		{
			std::map<std::string, int> result =
			{
				{ "a", 1 },
				{ "b", 1 },
				{ "c", 1 },
				{ "d", 1 },
				{ "e", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(function_call)
		{
			std::map<std::string, int> result =
			{
				{ "a", 1 },
				{ "b", 1 },
				{ "c", 1 },
				{ "func", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(string_initialization)
		{
			std::map<std::string, int> result =
			{
				{ "std", 1 },
				{ "string", 1 },
				{ "s", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(single_line_comment)
		{
			std::map<std::string, int> result =
			{
				{ "a", 1 },
				{ "b", 1 },
				{ "c", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(multiline_comment)
		{
			std::map<std::string, int> result =
			{
				{ "a", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(multiline_comment2)
		{
			std::map<std::string, int> result =
			{
				{ "a", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(tabs)
		{
			std::map<std::string, int> result =
			{
				{ "a", 1 },
				{ "b", 1 },
				{ "c", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}
	};

	TEST_CLASS(function_declaration)
	{
	public:
		TEST_METHOD(empty_main_function)
		{
			std::map<std::string, int> result =
			{
				{ "main", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(main_function_with_return)
		{
			std::map<std::string, int> result =
			{
				{ "main", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(main_function_with_variable_return)
		{
			std::map<std::string, int> result =
			{
				{ "main", 1 },
				{ "a", 2 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(function_with_arguments)
		{
			std::map<std::string, int> result =
			{
				{ "func", 1 },
				{ "a", 1 },
				{ "b", 1 },
				{ "c", 1 },
				{ "stream", 1 },
				{ "string", 1 },
				{ "iostream", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(function1)
		{
			std::map<std::string, int> result =
			{
				{ "a", 1 },
				{ "b", 1 },
				{ "string", 1 },
				{ "ptr", 1 },
				{ "get", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}
	};

	TEST_CLASS(macros_usage)
	{
	public:
		TEST_METHOD(system_include_directives)
		{
			std::map<std::string, int> result =
			{
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(user_include_directives)
		{
			std::map<std::string, int> result =
			{
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(define_directives)
		{
			std::map<std::string, int> result =
			{
				{ "a", 1 },
				{ "p", 1 },
				{ "value", 2 },
				{ "pi", 2 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}
	};

	TEST_CLASS(loops)
	{
	public:
		TEST_METHOD(for_loop)
		{
			std::map<std::string, int> result =
			{
				{ "i", 3 },
				{ "a", 1 },
				{ "b", 1 },
				{ "size", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(for_loop2)
		{
			std::map<std::string, int> result =
			{
				{ "i", 3 },
				{ "a", 1 },
				{ "b", 1 },
				{ "size", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(for_each_loop)
		{
			std::map<std::string, int> result =
			{
				{ "c", 1 },
				{ "line", 1 },
				{ "do_something", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(for_each_loop2)
		{
			std::map<std::string, int> result =
			{
				{ "c", 1 },
				{ "line", 1 },
				{ "do_something", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(while_loop)
		{
			std::map<std::string, int> result =
			{
				{ "start", 2 },
				{ "end", 2 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(while_loop2)
		{
			std::map<std::string, int> result =
			{
				{ "start", 2 },
				{ "end", 2 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}
	};

	TEST_CLASS(conditionals)
	{
	public:
		TEST_METHOD(if_block)
		{
			std::map<std::string, int> result =
			{
				{ "t", 1 },
				{ "a", 1 },
				{ "b", 1 },
				{ "func", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(if_block2)
		{
			std::map<std::string, int> result =
			{
				{ "t", 1 },
				{ "a", 1 },
				{ "b", 1 },
				{ "func", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(if_block_complex)
		{
			std::map<std::string, int> result =
			{
				{ "t", 1 },
				{ "a", 2 },
				{ "b", 2 },
				{ "c", 1 },
				{ "d", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(if_block_nested)
		{
			std::map<std::string, int> result =
			{
				{ "a", 2 },
				{ "b", 2 },
				{ "c", 2 },
				{ "d", 2 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(if_else_block)
		{
			std::map<std::string, int> result =
			{
				{ "a", 2 },
				{ "b", 2 },
				{ "c", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(if_else_block2)
		{
			std::map<std::string, int> result =
			{
				{ "a", 2 },
				{ "b", 2 },
				{ "c", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}
	};

	TEST_CLASS(ternary_operator)
	{
	public:
		TEST_METHOD(two_ternary_operators)
		{
			std::map<std::string, int> result =
			{
				{ "a", 1 },
				{ "b", 1 },
				{ "c", 1 },
				{ "d", 1 },
				{ "e", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(two_ternary_operators2)
		{
			std::map<std::string, int> result =
			{
				{ "a", 1 },
				{ "b", 1 },
				{ "c", 1 },
				{ "d", 1 },
				{ "e", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}
	};

	TEST_CLASS(complex_expressions)
	{
	public:
		TEST_METHOD(math_expression)
		{
			std::map<std::string, int> result =
			{
				{ "std", 1 },
				{ "string", 1 },
				{ "a", 2 },
				{ "b", 1 },
				{ "c", 1 },
				{ "d", 3 },
				{ "f", 4 },
				{ "s", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(nested_function_calls)
		{
			std::map<std::string, int> result =
			{
				{ "a", 1 },
				{ "b", 2 },
				{ "c", 1 },
				{ "d", 1 },
				{ "e", 1 },
				{ "f", 1 },
				{ "g", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}
	};

	TEST_CLASS(templates)
	{
	public:
		TEST_METHOD(template_type_instantiation)
		{
			std::map<std::string, int> result =
			{
				{ "vector", 1 },
				{ "map", 1 },
				{ "string", 1 },
				{ "a", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(template_function_instantiation)
		{
			std::map<std::string, int> result =
			{
				{ "make_shared", 1 },
				{ "map", 1 },
				{ "string", 1 },
				{ "a", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(template_object_creation)
		{
			std::map<std::string, int> result =
			{
				{ "o", 1 },
				{ "object", 1 },
				{ "string", 1 },
				{ "map", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(template_type_declaration)
		{
			std::map<std::string, int> result =
			{
				{ "T", 2 },
				{ "Y", 2 },
				{ "V", 2 },
				{ "c", 1 },
				{ "other", 1 },
				{ "var1", 1 },
				{ "get", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}

		TEST_METHOD(template_function_declaration)
		{
			std::map<std::string, int> result =
			{
				{ "T", 2 },
				{ "Y", 2 },
				{ "V", 2 },
				{ "get", 1 },
				{ "var1", 1 },
				{ "var2", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}
	};

	TEST_CLASS(class_declaration)
	{
	public:
		TEST_METHOD(class1)
		{
			std::map<std::string, int> result =
			{
				{ "c", 1 },
				{ "other", 1 },
				{ "other2", 1 },
				{ "get", 1 },
				{ "value", 1 },
				{ "empty", 1 },
				{ "add", 1 },
				{ "type", 1 },
				{ "v", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}
	};

	TEST_CLASS(variable_name_restrictiona)
	{
	public:
		TEST_METHOD(long_names)
		{
			std::map<std::string, int> result =
			{
				{ "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 1 },
				{ "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb", 1 },
				{ "length255", 1 },
				{ "length256", 1 },
				{ "length257", 1 },
			};
			Assert::IsTrue(get_parsed_result(__FUNCTION__) == result);
		}
	};
}
