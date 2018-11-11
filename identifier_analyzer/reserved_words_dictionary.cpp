#include "reserved_words_dictionary.h"

bool reserved_words_dictionary::is_reserved_word(std::string word) const
{
	return reserved_words.find(word) != reserved_words.cend();
}