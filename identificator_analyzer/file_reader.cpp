#include "file_reader.h"
#include <string>
#include "io_exception.h"

file_reader::file_reader(std::string file_name)
{
	open_file(file_name);
}

void file_reader::read_word(std::string& destination)
{
	check_if_open();
	input_file >> destination;
}

void file_reader::read_line(std::string& destination)
{
	check_if_open();
	getline(input_file, destination);
}

bool file_reader::read_words_till_end(std::string& destination)
{
	auto result = !input_file.eof();
	if (result)
	{
		read_word(destination);
		return result;
	}
	else
	{
		return result;
	}
}

void file_reader::open_file(const std::string& file_name)
{
	input_file.open(file_name);
}

void file_reader::close_file()
{
	input_file.close();
}

void file_reader::check_if_open() const
{
	if (!input_file.is_open())
	{
		throw io_exception("File isn't opened");
	}
}