#pragma once
#include <map>

/** Класс для хранения данных о наличии и количестве различных идентификаторов */
class parse_result
{
public:
	/** Добавить новый идентификатор в словарь */
	void add_identifier(const std::string& word, int amount) { identifiers[word] += amount; }

	/** Вернуть добавленные идентификаторы */
	auto get_identifiers() const { return identifiers; }

private:
	std::map<std::string, int> identifiers;
};
