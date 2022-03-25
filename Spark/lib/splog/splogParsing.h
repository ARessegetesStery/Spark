#pragma once

/* Uses {+num+} to represent the num-th variable in the coming variable list
 * TODO (not urgent) add "/+{" or "/+}" to make printing string "{0}" possible
 * */

namespace splog {

	/* ---- Converting Possible Types to String ---- */
	std::string spToString(std::string t)
	{
		// uses pass-by-value to prevent infinite recurring
		return t;
	}

	template<typename T>
	std::string spToString(T& t)
	{
		const size_t code = typeid(t).hash_code();
		if (typeid(T).hash_code() == typeid(std::string).hash_code())
		{
			return spToString(t);
		}
		if (code == typeid(int).hash_code() || code == typeid(long long int).hash_code() ||
			code == typeid(unsigned int).hash_code() || code == typeid(unsigned long long int).hash_code() ||
			code == typeid(float).hash_code() || code == typeid(double).hash_code() || 
			code == typeid(long double).hash_code())
		{
			return std::to_string(t);
		}
		else if (code == typeid(char).hash_code())
		{
			std::string res(1, t);
			return res;
		}
		else
		{
			return "_NOT_SUPPORTED_TYPE";
		}
	}
	/* --------------------------------------------- */

	/* --- Dispatching --- */
	// case 1
	std::string dispatchLogEvent(std::string str)
	{
		return str;
	}

	// case 2
	template <typename T, typename... Args>
	std::string dispatchLogEvent(std::string str, const T& t, const Args&... params)
	{
		dispatchLogEvent(str, 0, t, params...);
	}

	template <typename T>
	void dispatchLogEvent(std::string& str, int paramCnt, const T& t)
	{
		std::string varSign = "{" + spToString(paramCnt) + "}";
		size_t index = str.find(varSign);
		if (index == std::string::npos)
		{
			dispatchLogEvent("[SYNTAX ERROR: FEWER MACHING PARAM] ORIGINAL: " + str);
			return;
		}
		str.replace(index, 3, spToString(t));
		while (true)
		{
			index = str.find(varSign, index + 1);
			if (index != std::string::npos)
				str.replace(index, 3, spToString(t));
			else
				break;
		}
		dispatchLogEvent(str);
	}

	template <typename T, typename... Args>
	void dispatchLogEvent(std::string& str, int paramCnt, const T& t, const Args&... params)
	{
		std::string varSign = "{" + spToString(paramCnt) + "}";
		size_t index = str.find(varSign);
		if (index == std::string::npos)
		{
			dispatchLogEvent("[SYNTAX ERROR: FEWER MACHING PARAM] ORIGINAL: " + str);
			return;
		}
		str.replace(index, 3, spToString(t));
		while (true)
		{
			index = str.find(varSign, index + 1);
			if (index != std::string::npos)
				str.replace(index, 3, spToString(t));
			else
				break;
		}
		dispatchLogEvent(str, paramCnt + 1, params...);
	}
	/* ----------------- */

}