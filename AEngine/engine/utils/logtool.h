#pragma once
#include<fstream>


namespace AEngine
{

enum LogLevel 
{
	INFO,
	WARNNING,
	ERROR
};

class LogTool
{
public:
	static LogTool& Instance();
	void LogArgs(LogLevel level, const char* format, va_list);
	void LogArgs(LogLevel level, const char* format, ...);
	void Log(LogLevel level, const char* info);
	void LogInfo(const char* format, ...);
	void LogWarning(const char* format, ...);
	void LogError(const char* format, ...);

private:
	LogTool();
	~LogTool();
	std::fstream* m_File;
};


}