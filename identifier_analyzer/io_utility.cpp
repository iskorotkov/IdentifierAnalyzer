#include "io_utility.h"

std::ostream& operator<<(std::ostream& out, const std::map<std::string, int>& m)
{
	for (const auto& it : m)
	{
		out << it.first << ' ' << it.second << '\n';
	}
	return out;
}

std::ostream& operator<<(std::ostream& out, const std::string& s)
{
	for (const auto& it : s)
	{
		out << s;
	}
	return out;
}