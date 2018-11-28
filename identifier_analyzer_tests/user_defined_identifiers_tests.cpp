#include "CppUnitTest.h"
#include <map>
#include <string>
#include "../identifier_analyzer/reserved_words_dictionary.cpp"
#include "../identifier_analyzer/word_parser.cpp"
#include "../identifier_analyzer/file_parser.cpp"
#include "../identifier_analyzer/word_filter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

const std::string path_to_folder = "D:/Projects/identifier_analyzer/identifier_analyzer_tests/examples/";

namespace user_defined_identifiers {
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
}
