#pragma once
#include "data.h"
#include <string>

class analyzer
{
public:
	virtual data analyze(const std::string& source) = 0;
};
