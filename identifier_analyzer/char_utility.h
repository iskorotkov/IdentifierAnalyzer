#pragma once
#include <string>

/** Специальные методы для работы с символами и строками */
class char_utility
{
public:
	/** Находит конец строкового литерала (string literal) */
	static size_t find_string_literal_end(const std::string& line, size_t begin);

	/** Проверяет, является ли символ кавычкой */
	static bool is_quotation(char c);

	/** Проверяет, является ли символ числом */
	static bool is_digit(char c) { return c >= '0' && c <= '9'; }

	/** Проверяет, является ли символ буквой */
	static bool is_letter(char c) { return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'; }

	/** Проверяет, является ли символ символом _ */
	static bool is_underscore(char c) { return c == '_'; }

	/** Проверяет, является ли символ какой-либо скобкой */
	static bool is_brace(char c);

	/** Проверяет, является ли символ символом арифметической, логической или бинарной операцией */
	static bool is_operation_sign(char c);
};

