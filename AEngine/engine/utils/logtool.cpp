#include <cstdarg>
#include "logtool.h"
#include "filereader.h"


namespace AEngine {

	static const char* LOG_FILE = "log.txt";
	static const int MAX_LOG_LEN = 1024;

	static string GetLogLevelStr(LogLevel l)
	{
		switch (l)
		{
		case AEngine::INFO:
			return "INFO";
		case AEngine::WARNNING:
			return "WARNNING";
		case AEngine::ERROR:
			return "ERROR";
		default:
			return "INFO";
		}
	}

	LogTool::LogTool()
	{
		m_File = FileReader::Instance().OpenFile(LOG_FILE, FileMode::OUT);
	}

	LogTool::~LogTool() 
	{
		FileReader::Instance().CloseFile(m_File);
		delete m_File;
		m_File = nullptr;
	}

	LogTool& LogTool::Instance()
	{
		static LogTool inst;
		return inst;
	}

	void LogTool::LogArgs(LogLevel level, const char* format, va_list args)
	{
		char szData[MAX_LOG_LEN];
		try
		{
			vsnprintf(szData, MAX_LOG_LEN, format, args);
			string head = "[" + GetLogLevelStr(level) + ":]";
			string info(szData);
			FileReader::Instance().WriteToStream(m_File, info.c_str(),true);
		}
		catch (...) 
		{ 
			std::cout << "Error log" << std::endl; 
		}
	}

	void LogTool::LogArgs(LogLevel level, const char* format, ...)
	{
		char szData[MAX_LOG_LEN];
		try
		{
			va_list args;
			va_start(args, format);
			vsnprintf(szData, MAX_LOG_LEN, format, args);
			va_end(args);
			string head = "[" + GetLogLevelStr(level) + ":]";
			string info(szData);
			FileReader::Instance().WriteToStream(m_File, info.c_str(), true);
		}
		catch (...)
		{
			std::cout << "Error log" << std::endl;
		}
	}

	void LogTool::Log(LogLevel level, const char* info)
	{
		string head = "[" + GetLogLevelStr(level) + ":]";
		string content(info);
		FileReader::Instance().WriteToStream(m_File, content.c_str(), true);
	}

	void LogTool::LogInfo(const char* format, ...)
	{
		va_list args;
		va_start(args, format);
		LogArgs(LogLevel::INFO, format, args);
		va_end(args);
	}

	void LogTool::LogWarning(const char* format, ...)
	{
		va_list args;
		va_start(args, format);
		LogArgs(LogLevel::WARNNING, format, args);
		va_end(args);
	}

	void LogTool::LogError(const char* format, ...)
	{
		va_list args;
		va_start(args, format);
		LogArgs(LogLevel::ERROR, format, args);
		va_end(args);
	}
}