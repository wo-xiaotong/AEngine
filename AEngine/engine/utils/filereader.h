#pragma once

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <memory>
using std::string;
using std::ios;

namespace AEngine
{

enum FileMode
{
	IN = ios::in,
	OUT = ios::out,
	APP = ios::app,
	BIN = ios::binary,
	END = ios::ate,
};

class FileReader
{
public:
	static FileReader & Instance();
	string ReadFromFile(const char* filename,FileMode mode = FileMode::BIN);
	void WriteToFile(const char* filename, const char* info, bool lineBreak = false);
	void WriteToStream(std::fstream *file, const char* info, bool lineBreak = false);
	std::fstream* OpenFile(const char* filename, FileMode mode);
	void CloseFile(std::fstream*);
};

};