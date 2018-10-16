#include "file_reader.h"
#include <string>
#include "io_exception.h"

file_reader::file_reader(std::string file_name)
{
	open_file(file_name);
}

std::string file_reader::read_word()
{
	if (!input_file.is_open())
	{
		throw io_exception("File isn't opened");
	}
	std::string s;
	input_file >> s;
	return s;
}

std::string file_reader::read_line()
{
	if (!input_file.is_open())
	{
		throw io_exception("File isn't opened");
	}
	std::string s;
	getline(input_file, s);
	return s;
}

void file_reader::open_file(std::string file_name)
{
	input_file.open(file_name);
}

void file_reader::close_file()
{
	input_file.close();
}