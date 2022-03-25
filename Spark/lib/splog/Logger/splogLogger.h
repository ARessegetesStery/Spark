#pragma once

namespace splog {

	class Logger
	{
	public:
		Logger(std::string name) : m_name(name) {   }
		~Logger();

		/* --- Setting up Logging types --- */
		template <typename... Args>
		void info(Args... params)
		{
			genLog(splog::LogType::Info, params...);
		}

		template <typename... Args>
		void trace(Args... params)
		{
			genLog(splog::LogType::Trace, params...);
		}

		template <typename... Args>
		void warning(Args... params)
		{
			genLog(splog::LogType::Warning, params...);
		}

		template <typename... Args>
		void error(Args... params)
		{
			genLog(splog::LogType::Error, params...);
		}

		template <typename... Args>
		void fatal(Args... params)
		{
			genLog(splog::LogType::Fatal, params...);
		}
		/* -------------------------------- */

		static Logger* genLogger(std::string name)
		{
			return new Logger(name);
		}

		void setLogFormat(std::string str)
		{
			//spSetupLoggerFormat(str);
			m_fmtInfo = str;
		}

		// Following are not for users

	private:
		std::string m_name;
		std::string m_fmtInfo;

		void spConfigLogFormat(LogType type, std::string& str, std::string& fmt);

		template <typename... Args>
		void genLog(LogType type, Args... params)
		{
			std::string strWParams = dispatchLogEvent(params...);
			spConfigLogFormat(type, strWParams, m_fmtInfo);
		}

	};

}