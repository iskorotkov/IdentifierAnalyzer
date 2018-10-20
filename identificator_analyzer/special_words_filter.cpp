#include "special_words_filter.h"
#include <set>

bool special_words_filter::is_special_word(std::string word)
{
	static const std::set<std::string> special_words =
	{
		"#include",
		"using",
		"namespace",
		"return",
	};

	return special_words.find(word) != special_words.cend();
}