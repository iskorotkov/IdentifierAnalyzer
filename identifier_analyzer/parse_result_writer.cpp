#include "parse_result_writer.h"
#include "parse_result.h"
#include <map>
#include <ostream>

void parse_result_writer::write_result(const parse_result& result, std::string file_name) const
{
	std::ofstream stream(file_name);
	auto parsed_words = result.get_used_identifiers();
	while (!parsed_words.empty())
	{
		auto it = get_most_frequent_word(parsed_words);
		write_pair(*it, stream);
		stream << '\n';
		parsed_words.erase(it->first);
	}
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

void parse_result_writer::write_pair(const std::pair<const std::string, int>& p, std::ofstream& stream) const
{
	stream << p.first << " " << p.second;
}

std::ostream& operator<<(std::ostream& stream, const std::string s)
{
	for (auto c : s)
	{
		stream << c;
	}
	return stream;
}