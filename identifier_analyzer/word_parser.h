#pragma once
#include <string>
#include <map>
#include "word_filter.h"

/** Класс для анализа отдельных слов */
class word_parser
{
public:
	/** Обрабатывает данное слово и находит в нем идентификаторы */
	std::map<std::string, int> parse_word(const std::string& word) const;

private:
	word_filter filter;
};
