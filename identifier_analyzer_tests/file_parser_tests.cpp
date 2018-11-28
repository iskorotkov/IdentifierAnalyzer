#include "CppUnitTest.h"
#include <map>
#include <string>
#include "../identifier_analyzer/reserved_words_dictionary.cpp"
#include "../identifier_analyzer/word_parser.cpp"
#include "../identifier_analyzer/file_parser.cpp"
#include "../identifier_analyzer/word_filter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

const std::string path_to_folder = "D:/Projects/identifier_analyzer/identifier_analyzer_tests/examples/";

namespace file_parser_tests {
	TEST_CLASS(single_expression)
	{
	public:

		TEST_METHOD(assignment)
		{
			file_parser parser(path_to_folder + "test1.txt");
			std::map<std::string, int> result =
			{
				{ "a", 1 },
				{ "b", 1 },
				{ "c", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(assignment_with_initializer_list)
		{
			file_parser parser(path_to_folder + "test2.txt");
			std::map<std::string, int> result =
			{
				{ "s", 1 },
				{ "e", 1 },
				{ "string", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(multiple_variable_initialization)
		{
			file_parser parser(path_to_folder + "test3.txt");
			std::map<std::string, int> result =
			{
				{ "a", 1 },
				{ "b", 1 },
				{ "c", 1 },
				{ "d", 1 },
				{ "e", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(function_call)
		{
			file_parser parser(path_to_folder + "test4.txt");
			std::map<std::string, int> result =
			{
				{ "a", 1 },
				{ "b", 1 },
				{ "c", 1 },
				{ "func", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(string_initialization)
		{
			file_parser parser(path_to_folder + "test5.txt");
			std::map<std::string, int> result =
			{
				{ "std", 1 },
				{ "string", 1 },
				{ "s", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(single_line_comment)
		{
			file_parser parser(path_to_folder + "test6.txt");
			std::map<std::string, int> result =
			{
				{ "a", 1 },
				{ "b", 1 },
				{ "c", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(multiline_comment)
		{
			file_parser parser(path_to_folder + "test7.txt");
			std::map<std::string, int> result =
			{
				{ "a", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(multiline_comment2)
		{
			file_parser parser(path_to_folder + "test8.txt");
			std::map<std::string, int> result =
			{
				{ "a", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(tabs)
		{
			file_parser parser(path_to_folder + "test11.txt");
			std::map<std::string, int> result =
			{
				{ "a", 1 },
				{ "b", 1 },
				{ "c", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}
	};

	TEST_CLASS(function_declaration)
	{
	public:
		TEST_METHOD(empty_main_function)
		{
			file_parser parser(path_to_folder + "test9.txt");
			std::map<std::string, int> result =
			{
				{ "main", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(main_function_with_return)
		{
			file_parser parser(path_to_folder + "test10.txt");
			std::map<std::string, int> result =
			{
				{ "main", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(main_function_with_variable_return)
		{
			file_parser parser(path_to_folder + "test12.txt");
			std::map<std::string, int> result =
			{
				{ "main", 1 },
				{ "a", 2 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(function_with_arguments)
		{
			file_parser parser(path_to_folder + "test13.txt");
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
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(function1)
		{
			file_parser parser(path_to_folder + "test38.txt");
			std::map<std::string, int> result =
			{
				{ "a", 1 },
				{ "b", 1 },
				{ "string", 1 },
				{ "ptr", 1 },
				{ "get", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}
	};

	TEST_CLASS(macros_usage)
	{
	public:
		TEST_METHOD(system_include_directives)
		{
			file_parser parser(path_to_folder + "test14.txt");
			std::map<std::string, int> result =
			{
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(user_include_directives)
		{
			file_parser parser(path_to_folder + "test15.txt");
			std::map<std::string, int> result =
			{
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(define_directives)
		{
			file_parser parser(path_to_folder + "test16.txt");
			std::map<std::string, int> result =
			{
				{ "a", 1 },
				{ "p", 1 },
				{ "value", 2 },
				{ "pi", 2 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}
	};

	TEST_CLASS(loops)
	{
	public:
		TEST_METHOD(for_loop)
		{
			file_parser parser(path_to_folder + "test17.txt");
			std::map<std::string, int> result =
			{
				{ "i", 3 },
				{ "a", 1 },
				{ "b", 1 },
				{ "size", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(for_loop2)
		{
			file_parser parser(path_to_folder + "test20.txt");
			std::map<std::string, int> result =
			{
				{ "i", 3 },
				{ "a", 1 },
				{ "b", 1 },
				{ "size", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(for_each_loop)
		{
			file_parser parser(path_to_folder + "test18.txt");
			std::map<std::string, int> result =
			{
				{ "c", 1 },
				{ "line", 1 },
				{ "do_something", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(for_each_loop2)
		{
			file_parser parser(path_to_folder + "test21.txt");
			std::map<std::string, int> result =
			{
				{ "c", 1 },
				{ "line", 1 },
				{ "do_something", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(while_loop)
		{
			file_parser parser(path_to_folder + "test19.txt");
			std::map<std::string, int> result =
			{
				{ "start", 2 },
				{ "end", 2 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(while_loop2)
		{
			file_parser parser(path_to_folder + "test22.txt");
			std::map<std::string, int> result =
			{
				{ "start", 2 },
				{ "end", 2 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}
	};

	TEST_CLASS(conditionals)
	{
	public:
		TEST_METHOD(if_block)
		{
			file_parser parser(path_to_folder + "test23.txt");
			std::map<std::string, int> result =
			{
				{ "t", 1 },
				{ "a", 1 },
				{ "b", 1 },
				{ "func", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(if_block2)
		{
			file_parser parser(path_to_folder + "test26.txt");
			std::map<std::string, int> result =
			{
				{ "t", 1 },
				{ "a", 1 },
				{ "b", 1 },
				{ "func", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(if_block_complex)
		{
			file_parser parser(path_to_folder + "test24.txt");
			std::map<std::string, int> result =
			{
				{ "t", 1 },
				{ "a", 2 },
				{ "b", 2 },
				{ "c", 1 },
				{ "d", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(if_block_nested)
		{
			file_parser parser(path_to_folder + "test25.txt");
			std::map<std::string, int> result =
			{
				{ "a", 2 },
				{ "b", 2 },
				{ "c", 2 },
				{ "d", 2 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(if_else_block)
		{
			file_parser parser(path_to_folder + "test27.txt");
			std::map<std::string, int> result =
			{
				{ "a", 2 },
				{ "b", 2 },
				{ "c", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(if_else_block2)
		{
			file_parser parser(path_to_folder + "test28.txt");
			std::map<std::string, int> result =
			{
				{ "a", 2 },
				{ "b", 2 },
				{ "c", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}
	};

	TEST_CLASS(ternary_operator)
	{
	public:
		TEST_METHOD(two_ternary_operators)
		{
			file_parser parser(path_to_folder + "test29.txt");
			std::map<std::string, int> result =
			{
				{ "a", 1 },
				{ "b", 1 },
				{ "c", 1 },
				{ "d", 1 },
				{ "e", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(two_ternary_operators2)
		{
			file_parser parser(path_to_folder + "test30.txt");
			std::map<std::string, int> result =
			{
				{ "a", 1 },
				{ "b", 1 },
				{ "c", 1 },
				{ "d", 1 },
				{ "e", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}
	};

	TEST_CLASS(complex_expressions)
	{
	public:
		TEST_METHOD(math_expression)
		{
			file_parser parser(path_to_folder + "test31.txt");
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
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(nested_function_calls)
		{
			file_parser parser(path_to_folder + "test32.txt");
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
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}
	};

	TEST_CLASS(templates)
	{
	public:
		TEST_METHOD(template_type_instantiation)
		{
			file_parser parser(path_to_folder + "test33.txt");
			std::map<std::string, int> result =
			{
				{ "vector", 1 },
				{ "map", 1 },
				{ "string", 1 },
				{ "a", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(template_function_instantiation)
		{
			file_parser parser(path_to_folder + "test34.txt");
			std::map<std::string, int> result =
			{
				{ "make_shared", 1 },
				{ "map", 1 },
				{ "string", 1 },
				{ "a", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(template_object_creation)
		{
			file_parser parser(path_to_folder + "test35.txt");
			std::map<std::string, int> result =
			{
				{ "o", 1 },
				{ "object", 1 },
				{ "string", 1 },
				{ "map", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(template_type_declaration)
		{
			file_parser parser(path_to_folder + "test36.txt");
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
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}

		TEST_METHOD(template_function_declaration)
		{
			file_parser parser(path_to_folder + "test37.txt");
			std::map<std::string, int> result =
			{
				{ "T", 2 },
				{ "Y", 2 },
				{ "V", 2 },
				{ "get", 1 },
				{ "var1", 1 },
				{ "var2", 1 },
			};
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}
	};

	TEST_CLASS(class_declaration)
	{
	public:
		TEST_METHOD(class1)
		{
			file_parser parser(path_to_folder + "test39.txt");
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
			Assert::IsTrue(parser.get_user_defined_words() == result);
		}
	};
}
