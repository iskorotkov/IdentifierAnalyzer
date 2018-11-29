#pragma once
#include <string>
#include "parse_result.h"
#include "reserved_words_dictionary.h"
#include "word_parser.h"

/** Класс для открытия и обработки содержимого файла */
class file_parser
{
public:
	file_parser() {}
	file_parser(const std::string& filename);

	/** Обрабатывает содержимое файла и считает количество встреченных идентификаторов */
	void parse_file(const std::string& file_name);

	/** Вовзращает имена и количество ключевых (зарезервированных) слов */
	auto get_reserved_words() const { return reserved_words.get_identifiers(); }

	/** Вовзращает имена и количество не ключевых (не зарезервированных) слов */
	auto get_user_defined_words() const { return user_defined_words.get_identifiers(); }

private:
	parse_result reserved_words;
	parse_result user_defined_words;
	reserved_words_dictionary dictionary;
	word_parser parser;
	bool is_commented_out = false;

	/** Разделяет слова на ключевые и не ключевые и добавляет их в соответствубщие списки */
	void add_words(const std::map<std::string, int>& words);

	/** Добавляет данное слово в словарь ключевых слов */
	void add_reserved_word(const std::string& word, int amount) { reserved_words.add_identifier(word, amount); }

	/** Добавляет данное слово в словарь НЕ ключевых слов */
	void add_user_defined_word(const std::string& word, int amount) { user_defined_words.add_identifier(word, amount); }

	/** Анализирует строку и разбивает ее на слова для дальнейшего анализа */
	void parse_line(std::string& line);

	/** Удаляет директивы препроцессора, если они есть */
	void analyze_if_preprocessor_directive(std::string& line);

	/** Удаляет комментарии (однострочные и многострочные), если они есть */
	void analyze_if_comment(std::string& line);

	/** Находит конец строкового литерала (string literal) */
	std::string::const_iterator find_string_literal_end(std::string::const_iterator begin, std::string::const_iterator end) const;
	size_t find_string_literal_end(const std::string& line, size_t begin) const;
};
