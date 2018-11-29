#pragma once
#include <string>

/** ����������� ������ ��� ������ � ��������� � �������� */
class char_utility
{
public:
	/** ������� ����� ���������� �������� (string literal) */
	static size_t find_string_literal_end(const std::string& line, size_t begin);

	/** ���������, �������� �� ������ �������� */
	static bool is_quotation(char c);

	/** ���������, �������� �� ������ ������ */
	static bool is_digit(char c) { return c >= '0' && c <= '9'; }

	/** ���������, �������� �� ������ ������ */
	static bool is_letter(char c) { return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'; }

	/** ���������, �������� �� ������ �������� _ */
	static bool is_underscore(char c) { return c == '_'; }

	/** ���������, �������� �� ������ �����-���� ������� */
	static bool is_brace(char c);

	/** ���������, �������� �� ������ �������� ��������������, ���������� ��� �������� ��������� */
	static bool is_operation_sign(char c);
};

