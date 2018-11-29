#pragma once
#include <string>

/** Класс для анализа слов и символов */
class word_filter
{
public:
	/**
	 * Определяет, подходит ли слово под критерии задачи
	 *
	 * Критерии: длина слова в промежутке [0;256] и является корректным идентификаторо языка C++, т. е. начинается с буквы латиницы, кириллицы или символа _, а все другие символы являются буквами латиницы, кириллицы, символами _ или цифрами
	 */
	bool is_valid_word(const std::string& word) const;

	/** Проверяет, является ли символ корректным первым символом идентификатора C++ */
	bool is_valid_first_character(const std::string& word) const;
	bool is_valid_first_character(char c) const;

	/** Проверяет, является ли символ корректным НЕпервым символом идентификатора C++ */
	bool is_valid_character(char c) const;

	/** Проверяет, является ли символ кавычкой */
	bool is_quotation(char c) const;

	/** Проверяет, чтобы длина была в промежутке [0;256] */
	bool is_valid_length(std::string word) const;

	/** Проверяет, является ли символ числом */
	bool is_digit(char c) const { return c >= '0' && c <= '9'; }

	/** Проверяет, является ли символ буквой */
	bool is_letter(char c) const { return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'; }

	/** Проверяет, является ли символ символом _ */
	bool is_underscore(char c) const { return c == '_'; }

	/** Проверяет, является ли символ какой-либо скобкой */
	bool is_brace(char c) const;

	/** Проверяет, является ли символ символом арифметической, логической или бинарной операцией */
	bool is_operation_sign(char c) const;
};
