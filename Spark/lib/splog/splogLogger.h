#pragma once

#include "splogCore.h"
#include "splogDecl.h"

namespace splog {

	//template <typename... Args>
	//std::string dispatchLogEvent(Args... params);

	Logger::Logger(std::string name) : m_name(name) {   }

	Logger::~Logger() {  };

	/* --- Setting up Logging types --- */
	template <typename... Args>
	void Logger::info(Args... params)
	{
		genLog(splog::LogType::Info, params...);
	}

	template <typename... Args>
	void Logger::trace(Args... params)
	{
		genLog(splog::LogType::Trace, params...);
	}

	template <typename... Args>
	void Logger::warning(Args... params)
	{
		genLog(splog::LogType::Warning, params...);
	}

	template <typename... Args>
	void Logger::error(Args... params)
	{
		genLog(splog::LogType::Error, params...);
	}

	template <typename... Args>
	void Logger::fatal(Args... params)
	{
		genLog(splog::LogType::Fatal, params...);
	}
	/* -------------------------------- */

	//static std::shared_ptr<Logger> Logger::genLogger(std::string name)
	//{
	//	std::shared_ptr<Logger> ptr(new Logger(name));
	//	return ptr;
	//}

	void Logger::setLogFormat(std::string str)
	{
		m_fmtInfo = str;
	}

	template <typename... Args>
	void Logger::genLog(LogType type, Args... params)
	{
		std::string strWParams = dispatchLogEvent(params...);
		spConfigLogFormat(type, strWParams, m_fmtInfo);
	}

	//class Logger
	//{
	//public:
	//	Logger(std::string name) : m_name(name) {   }
	//	~Logger() {  };

	//	/* --- Setting up Logging types --- */
	//	template <typename... Args>
	//	void info(Args... params)
	//	{
	//		genLog(splog::LogType::Info, params...);
	//	}

	//	template <typename... Args>
	//	void trace(Args... params)
	//	{
	//		genLog(splog::LogType::Trace, params...);
	//	}

	//	template <typename... Args>
	//	void warning(Args... params)
	//	{
	//		genLog(splog::LogType::Warning, params...);
	//	}

	//	template <typename... Args>
	//	void error(Args... params)
	//	{
	//		genLog(splog::LogType::Error, params...);
	//	}

	//	template <typename... Args>
	//	void fatal(Args... params)
	//	{
	//		genLog(splog::LogType::Fatal, params...);
	//	}
	//	/* -------------------------------- */

	//	static std::shared_ptr<Logger> genLogger(std::string name)
	//	{
	//		std::shared_ptr<Logger> ptr(new Logger(name));
	//		return ptr;
	//	}

	//	void setLogFormat(std::string str)
	//	{
	//		//spSetupLoggerFormat(str);
	//		m_fmtInfo = str;
	//	}

	//	// Following are not for users

	//private:
	//	std::string m_name;
	//	std::string m_fmtInfo;

	//	void spConfigLogFormat(LogType type, std::string& str, std::string& fmt);

	//	template <typename... Args>
	//	void genLog(LogType type, Args... params)
	//	{
	//		std::string strWParams = dispatchLogEvent(params...);
	//		spConfigLogFormat(type, strWParams, m_fmtInfo);
	//	}

	//};

}