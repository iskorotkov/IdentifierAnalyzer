#pragma once
#include "data.h"
#include "base_analyzer.h"

template<typename data_type>
class base_code_analyzer : public base_analyzer
{
public:
	virtual data_type analyze(const c_iter start, const c_iter end) = 0;

protected:
	data_type result;
};
