#pragma once

#include "splogCore.h"

/* This files includes all the declarations for splog
 * Include this in all header files potentially will use splog
 * For the implementation, please include splog.h
 * */

namespace splog {

	class Logger
	{
	public:
		Logger(std::string name);
		~Logger();

		/* --- Setting up Logging types --- */
		template <typename... Args>
		void info(Args... params);

		template <typename... Args>
		void trace(Args... params);

		template <typename... Args>
		void warning(Args... params);

		template <typename... Args>
		void error(Args... params);

		template <typename... Args>
		void fatal(Args... params);
		/* -------------------------------- */

		//static std::shared_ptr<Logger> genLogger(std::string name);

		static std::shared_ptr<Logger> Logger::genLogger(std::string name)
		{
			std::shared_ptr<Logger> ptr(new Logger(name));
			return ptr;
		}

		void setLogFormat(std::string str);

		// Following are not for users

	private:
		std::string m_name;
		std::string m_fmtInfo;

		void spConfigLogFormat(LogType type, std::string& str, std::string& fmt);

		template <typename... Args>
		void genLog(LogType type, Args... params);

	};

	std::string spToString(std::string t);

	template<typename T>
	std::string spToString(T& t);

	std::string dispatchLogEvent(std::string str);

	template <typename T, typename... Args>
	std::string dispatchLogEvent(std::string str, const T& t, const Args&... params);

	template <typename T>
	void dispatchLogEvent(std::string& str, int paramCnt, const T& t);

	template <typename T, typename... Args>
	void dispatchLogEvent(std::string& str, int paramCnt, const T& t, const Args&... params);

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

	template <typename... Args>
	void Logger::genLog(LogType type, Args... params)
	{
		std::string strWParams = dispatchLogEvent(params...);
		spConfigLogFormat(type, strWParams, m_fmtInfo);
	}
}