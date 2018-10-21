#pragma once
#include "data.h"
#include <string>

template<typename data_type>
class analyzer
{
public:
	virtual data_type analyze(const std::vector<char>& source) = 0;

protected:
	data_type result;
};
