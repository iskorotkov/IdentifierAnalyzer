#pragma once
#include <fstream>

class file_reader
{
public:
	file_reader() = default;
	file_reader(std::string file_name);

	template <typename T>
	T read_word()
	{
		T t;
		input_file >> t;
		return t;
	}

	std::string read_word();
	std::string read_line();
	void open_file(std::string file_name);
	void close_file();

private:
	std::ifstream input_file;
};
