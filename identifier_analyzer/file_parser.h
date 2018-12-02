#pragma once
#include <string>
#include "parse_result.h"
#include "reserved_words_dictionary.h"
#include "word_parser.h"

/** ����� ��� �������� � ��������� ����������� ����� */
class file_parser
{
public:
	file_parser() {}
	file_parser(const std::string& filename);

	/** ������������ ���������� ����� � ������� ���������� ����������� ��������������� */
	void parse_file(const std::string& file_name);

	/** ���������� ����� � ���������� �������� (�����������������) ���� */
	auto get_reserved_words() const { return reserved_words.get_identifiers(); }

	/** ���������� ����� � ���������� �� �������� (�� �����������������) ���� */
	auto get_user_defined_words() const { return user_defined_words.get_identifiers(); }

private:
	parse_result reserved_words;
	parse_result user_defined_words;
	reserved_words_dictionary dictionary;
	word_parser parser;
	bool is_commented_out = false;

	/** ��������� ����� �� �������� � �� �������� � ��������� �� � ��������������� ������ */
	void add_words(const std::map<std::string, int>& words);

	/** ��������� ������ ����� � ������� �������� ���� */
	void add_reserved_word(const std::string& word, int amount) { reserved_words.add_identifier(word, amount); }

	/** ��������� ������ ����� � ������� �� �������� ���� */
	void add_user_defined_word(const std::string& word, int amount) { user_defined_words.add_identifier(word, amount); }

	/** ����������� ������ � ��������� �� �� ����� ��� ����������� ������� */
	void parse_line(std::string& line);

	/** ������� ��������� �������������, ���� ��� ���� */
	void analyze_if_preprocessor_directive(std::string& line);

	/** ������� ����������� (������������ � �������������), ���� ��� ���� */
	void analyze_if_comment(std::string& line);

	/** ������� ��������� �������� (string literals), ���� ��� ���� */
	void analyze_if_string_literal(std::string& line);

	/** ������� ��������� �������� (string literals) � ����������� �� ���� ������ */
	void remove_literals_and_comments(std::string& line);
};
