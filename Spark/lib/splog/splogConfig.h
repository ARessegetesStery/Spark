#pragma once

#include "splogCore.h"

#ifdef _WIN32
	#include "Platform/Windows/splogWindowsConfig.h"
#elif __unix__

#elif __APPLE__

#elif __linux__

#endif

#include "Format/splogPatternFormat.h"

/* TODO (further fix) Enable colorizing only a segment of text in the line
 * TODO Setting up logging format 
 * 
 * */

namespace splog {

	void spSetupLoggingFormat(std::string& str)
	{

	}


	extern void spConfigLogColor(LogType type);

	void spConfigLogType(LogType type)
	{
		spConfigLogColor(type);
	}

	void spConfigLogFormat(std::string& str)
	{
		std::cout << str << std::endl;
	}

}