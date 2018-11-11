#pragma once
#include "parse_result.h"
#include <fstream>

class parse_result_writer
{
public:
	void write_result(const parse_result& result, std::string file_name) const;

private:
	std::map<std::string, int>::const_iterator get_most_frequent_word(const std::map<std::string, int>& words) const;
	void write_pair(const std::pair<const std::string, int>& p, std::ofstream& stream) const;
};

std::ostream& operator<<(std::ostream& stream, const std::string s);