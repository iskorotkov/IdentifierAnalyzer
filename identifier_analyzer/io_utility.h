#pragma once
#include <ostream>
#include <map>
#include <vector>
#include <string>

std::ostream& operator<<(std::ostream& out, const std::map<std::string, int>& m);

std::ostream& operator<<(std::ostream& out, std::string& s);

std::ostream& operator<<(std::ostream& out, std::vector<std::string> v);
