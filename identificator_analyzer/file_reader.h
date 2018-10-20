#pragma once
#include <fstream>

class file_reader
{
public:
	file_reader() = default;
	file_reader(std::string file_name);

	void read_word(std::string& destination);
	void read_line(std::string& destination);
	bool read_words_till_end(std::string& destination);

	void open_file(const std::string& file_name);
	void close_file();

private:
	std::ifstream input_file;

	void check_if_open() const;
};
