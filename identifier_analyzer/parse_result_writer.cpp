#include "parse_result_writer.h"
#include "parse_result.h"
#include <map>
#include <fstream>
#include <iomanip>

void parse_result_writer::write_result(std::map<std::string,int>& parsed_words, std::string file_name) const
{
	std::multimap<int, std::string> reversed_map;
	for (auto& it : parsed_words)
	{
		reversed_map.emplace(it.second, it.first);
	}
	std::ofstream stream(file_name);
	for (auto it = reversed_map.rbegin(), end = reversed_map.rend(); it != end; ++it)
	{
		write_pair(it->second, it->first, stream);
	}


	/*while (!parsed_words.empty())
	{
		auto it = get_most_frequent_word(parsed_words);
		write_pair(*it, stream);
		stream << '\n';
		parsed_words.erase(it->first);
	}*/
}

std::map<std::string, int>::const_iterator parse_result_writer::get_most_frequent_word(const std::map<std::string, int>& words) const
{
	auto result = words.cbegin();
	for (auto it = words.cbegin(), end = words.cend(); it != end; ++it)
	{
		if (it->second > result->second)
		{
			result = it;
		}
	}
	return result;
}

void parse_result_writer::write_pair(const std::string& name, int count, std::ofstream& stream) const
{
	stream << std::setw(word_column_size) << std::left << name.c_str()
		<< std::setw(count_column_size) << std::right << count
		<< '\n';
}
