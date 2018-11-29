#pragma once
#include <string>

/** ����� ��� ������� ���� � �������� */
class word_filter
{
public:
	/**
	 * ����������, �������� �� ����� ��� �������� ������
	 *
	 * ��������: ����� ����� � ���������� [0;256] � �������� ���������� �������������� ����� C++, �. �. ���������� � ����� ��������, ��������� ��� ������� _, � ��� ������ ������� �������� ������� ��������, ���������, ��������� _ ��� �������
	 */
	bool is_valid_word(const std::string& word) const;

	/** ���������, �������� �� ������ ���������� ������ �������� �������������� C++ */
	bool is_valid_first_character(const std::string& word) const;
	bool is_valid_first_character(char c) const;

	/** ���������, �������� �� ������ ���������� �������� �������� �������������� C++ */
	bool is_valid_character(char c) const;

	/** ���������, �������� �� ������ �������� */
	bool is_quotation(char c) const;

	/** ���������, ����� ����� ���� � ���������� [0;256] */
	bool is_valid_length(std::string word) const;

	/** ���������, �������� �� ������ ������ */
	bool is_digit(char c) const { return c >= '0' && c <= '9'; }

	/** ���������, �������� �� ������ ������ */
	bool is_letter(char c) const { return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'; }

	/** ���������, �������� �� ������ �������� _ */
	bool is_underscore(char c) const { return c == '_'; }

	/** ���������, �������� �� ������ �����-���� ������� */
	bool is_brace(char c) const;

	/** ���������, �������� �� ������ �������� ��������������, ���������� ��� �������� ��������� */
	bool is_operation_sign(char c) const;
};
