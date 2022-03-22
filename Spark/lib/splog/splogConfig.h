#pragma once

#include "splogCore.h"

extern enum LogType;

namespace splog {

	void configLogType(LogType type)
	{

	}

	void configLogFormat(std::string& str)
	{
		std::cout << str << std::endl;
	}

}