#pragma once
#include "parse_result.h"
#include <fstream>
#include <map>

class parse_result_writer
{
public:
	void write_result(std::map<std::string, int> result, std::string file_name) const;

private:
	const int word_column_size = 15;
	const int count_column_size = 3;

	std::map<std::string, int>::const_iterator get_most_frequent_word(const std::map<std::string, int>& words) const;
	void write_pair(const std::pair<const std::string, int>& p, std::ofstream& stream) const;
};
