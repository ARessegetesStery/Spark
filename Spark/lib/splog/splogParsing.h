#pragma once

#include "splogCore.h"

namespace splog {

	extern void configLogType(LogType type);
	extern void configLogFormat(std::string& str);

	template<typename T>
	std::string spdToString(T& t)
	{
		std::string type = typeid(t).name();
		if (type == "int" || type == "long int" || type == "long long int" ||
			type == "unsigned int" || type == "unsigned long long int" ||
			type == "float" || type == "double")
		{
			return std::to_string(t);
		}
		else
		{
			return "_NOT_SUPPORTED_TYPE";
		}
	}

	/* --- Dispatching --- */
	// case 1
	void dispatchLogEvent(LogType type, std::string str)
	{
		configLogType(type);
		configLogFormat(str);
	}

	// case 2
	template <typename T, typename... Args>
	void dispatchLogEvent(LogType type, std::string str, const T& t, Args&... params)
	{
		configLogType(type);
		dispatchLogEvent(str, 0, params...);
	}

	void dispatchLogEvent(std::string& str)
	{
		configLogFormat(str);
	}

	template <typename T>
	void dispatchLogEvent(std::string& str, unsigned int paramCnt, const T& t)
	{
		std::string varSign = "{" + spdToString(paramCnt) + "}";
		size_t index = str.find(varSign);
		if (index == std::string::npos)
			dispatchLogEvent("[SYNTAX ERROR: FEWER MACHING PARAM] ORIGINAL: " + str);
		while (true)
		{
			index = str.find(varSign, index + 1);
			if (index != std::string::npos)
				str.replace(index, 3, spdToString(t));
			else
				break;
		}
		dispatchLogEvent(str);
	}

	template <typename T, typename... Args>
	void dispatchLogEvent(std::string& str, unsigned int paramCnt, const T& t, Args&... params)
	{
		std::string varSign = "{" + spdToString(paramCnt) + "}";
		size_t index = str.find(varSign);
		if (index == std::string::npos)
			dispatchLogEvent("[SYNTAX ERROR: FEWER MACHING PARAM] ORIGINAL: " + str);
		while (true)
		{
			index = str.find(varSign, index + 1);
			if (index != std::string::npos)
				str.replace(index, 3, spdToString(t));
			else
				break;
		}
		dispatchLogEvent(str, paramCnt + 1, params...);
	}
	/* ----------------- */

}