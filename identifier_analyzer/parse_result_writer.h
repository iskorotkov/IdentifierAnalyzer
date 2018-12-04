#pragma once
#include "parse_result.h"
#include <fstream>
#include <map>

/** Класс для форматированного вывода результата в консоль */
class parse_result_writer
{
public:
	/** Выводит словарь строка-число в консоль */
	void write_result(std::map<std::string, int> result, std::string file_name) const;

private:
	/** Ширина колонки для имени идентификатора */
	const int word_column_size = 15;

	/** Ширина колонки для количества идентификаторов в тексте */
	const int count_column_size = 3;

	/** Находит наиболее часто встречаемый идентификатор в словаре */
	std::map<std::string, int>::const_iterator get_most_frequent_word(const std::map<std::string, int>& words) const;

	/** Выводит пару идентификатор-количество в два столбика с выравниванием */
	void write_pair(const std::pair<const std::string, int>& p, std::ofstream& stream) const;
};
