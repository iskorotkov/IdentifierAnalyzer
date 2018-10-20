#include "file_reader.h"
#include <string>
#include "io_exception.h"

file_reader::file_reader(std::string file_name)
{
	open_file(file_name);
	file_is_open = true;
}

void file_reader::read_word(std::string destination)
{
	if (!file_is_open)
	{
		throw io_exception("File isn't opened");
	}
	input_file >> destination;
}

void file_reader::read_line(std::string destination)
{
	if (!file_is_open)
	{
		throw io_exception("File isn't opened");
	}
	getline(input_file, destination);
}

void file_reader::open_file(std::string file_name)
{
	input_file.open(file_name);
	file_is_open = true;
}

void file_reader::close_file()
{
	input_file.close();
	file_is_open = false;
}

file_reader& file_reader::operator>>(std::string destination)
{
	read_word(destination);
}

file_reader::operator bool() const
{
	return static_cast<bool>(input_file);
}