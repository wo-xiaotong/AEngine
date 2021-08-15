#include "filereader.h"

namespace AEngine 
{
	static const char* ENDLINE = "\n";

	FileReader& FileReader::Instance()
	{
		static FileReader reader;
		return reader;
	}

	string FileReader::ReadFromFile(const char* filename, FileMode mode)
	{
		std::ifstream file(filename, mode);
		if (!file.is_open())
		{
			std::cout << "bad file" << filename << std::endl;
			return nullptr;
		}

		string content;
		content.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
		file.close();

		return std::move(content);
	}

	std::fstream* FileReader::OpenFile(const char* filename, FileMode mode)
	{
		std::fstream* file = new std::fstream();
		file->open(filename, mode);
		return file;
	}

	void FileReader::WriteToFile(const char* filename, const char* info, bool lineBreak)
	{
		std::ofstream file;
		file.open(filename, FileMode::IN);
		if (file.is_open())
		{
			file << info;
			if (lineBreak)
				file << ENDLINE;
		}
		file.close();
	}

	void FileReader::WriteToStream(std::fstream *file, const char* info,bool lineBreak)
	{
		if (file->is_open())
		{
			*file << info;
			if (lineBreak)
				*file << ENDLINE;
		}
	}

	void FileReader::CloseFile(std::fstream* file)
	{
		if (file->is_open())
		{
			file->close();
		}
	}

};