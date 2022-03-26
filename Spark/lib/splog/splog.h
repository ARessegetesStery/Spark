#pragma once

// TODO split the declaration and the definition

#include "splogCore.h"
#include "splogConfig.h"
#include "splogParsing.h"

/* All functions that are involved in using splog system is listed here
 * The extern declarations are the functions that may be used for 
 *     initializing or resetting any settings for the logging system
 *
 * */

//#define SPLOG_TRACE(...)     dispatchLogEvent(splog::LogType::Trace, __VA_ARGS__)
//#define SPLOG_INFO(...)      dispatchLogEvent(splog::LogType::Info, __VA_ARGS__)
//#define SPLOG_WARNING(...)   dispatchLogEvent(splog::LogType::Warning, __VA_ARGS__)
//#define SPLOG_ERROR(...)     dispatchLogEvent(splog::LogType::Error, __VA_ARGS__)
//#define SPLOG_FATAL(...)     dispatchLogEvent(splog::LogType::Fatal, __VA_ARGS__)	
