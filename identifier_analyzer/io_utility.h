#pragma once
#include <ostream>
#include <map>
#include <string>

std::ostream& operator<<(std::ostream& out, const std::map<std::string, int>& m);

std::ostream& operator<<(std::ostream& out, const std::string& s);
