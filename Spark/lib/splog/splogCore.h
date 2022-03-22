#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace splog {

	enum LogType
	{
		Trace = 0,
		Info = 1,
		Warning = 2,
		Error = 3,
		Fatal = 4
	};

#define SPLOG_TRACE(...)     dispatchLogEvent(splog::LogType::Trace, __VA_ARGS__)
#define SPLOG_INFO(...)      dispatchLogEvent(splog::LogType::Info, __VA_ARGS__)
#define SPLOG_WARNING(...)   dispatchLogEvent(splog::LogType::Warning, __VA_ARGS__)
#define SPLOG_ERROR(...)     dispatchLogEvent(splog::LogType::Error, __VA_ARGS__)
#define SPLOG_FATAL(...)     dispatchLogEvent(splog::LogType::Fatal, __VA_ARGS__)	

}