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
}
