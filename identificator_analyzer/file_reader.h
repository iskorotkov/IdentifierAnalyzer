#pragma once
#include <fstream>

class file_reader
{
public:
	file_reader() = default;
	file_reader(std::string file_name);

	template <typename T>
	void read_word(T destination)
	{
		input_file >> destination;
	}

	void read_word(std::string destination);
	void read_line(std::string destination);
	void open_file(std::string file_name);
	void close_file();

	file_reader& operator>>(std::string destinaton);
	operator bool() const;

private:
	std::ifstream input_file;
	bool file_is_open = false;
};
