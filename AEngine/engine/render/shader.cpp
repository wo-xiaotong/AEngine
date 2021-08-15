#include <iostream>
#include <memory>
#include "shader.h"
#include "utils\logtool.h"
#include "utils\filereader.h"


namespace AEngine 
{

	Shader::Shader()
	{
		Reset();
	}

	Shader::Shader(Shader&& other)
	{
		mPs = other.mPs;
		mPs = other.mPs;
		mProgram = other.mProgram;
		other.Reset();
	}

	bool Shader::GetShaderState(GLuint obj)
	{
		int infologLength = 0;
		int charsWritten = 0;
		char *infoLog;

		glGetShaderiv(obj, GL_INFO_LOG_LENGTH, &infologLength);
		if (infologLength > 0)
		{
			infoLog = (char *)malloc(infologLength);
			glGetShaderInfoLog(obj, infologLength, &charsWritten, infoLog);
			LogTool::Instance().LogError(infoLog);
			free(infoLog);
			return false;
		}

		return true;
	}

	bool Shader::GetProgramState(GLuint obj)
	{
		int infologLength = 0;
		int charsWritten = 0;
		char *infoLog;

		glGetProgramiv(obj, GL_INFO_LOG_LENGTH, &infologLength);
		if (infologLength > 0)
		{
			infoLog = (char *)malloc(infologLength);
			glGetProgramInfoLog(obj, infologLength, &charsWritten, infoLog);
			LogTool::Instance().LogError(infoLog);
			free(infoLog);
			return false;
		}
		return true;
	}

	void Shader::CreateFromFile(const char*vs,const char*ps)
	{
		auto vsStr = FileReader::Instance().ReadFromFile(vs);
		auto psStr = FileReader::Instance().ReadFromFile(ps);
		CreateFromStr(vsStr.c_str(), psStr.c_str());
	}

	void Shader::CreateFromStr(const char* vs,const char*ps)
	{
		 mVs = glCreateShader(GL_VERTEX_SHADER);
		 glShaderSource(mVs, 1,&vs, NULL);
		 glCompileShader(mVs);
		 auto vsState = GetShaderState(mVs);

		 mPs = glCreateShader(GL_FRAGMENT_SHADER);
		 glShaderSource(mPs, 1, &ps, NULL);
		 glCompileShader(mPs);
		 auto psState = GetShaderState(mPs);

		 if (vsState && psState)
		 {
			 mProgram = glCreateProgram();
			 glAttachShader(mProgram, mVs);
			 glAttachShader(mProgram, mPs);
			 auto programState = GetProgramState(mProgram);
			 if (programState) 
			 {
				 glLinkProgram(mProgram);
			 }
			 else 
			 {
				 LogTool::Instance().LogError("%s", "glCreateProgram->error");
			 }
		 }
		 else
		 {
			 LogTool::Instance().LogError("%s", "glCreateShader->error");
			 LogTool::Instance().LogError("%s", vs);
			 LogTool::Instance().LogError("%s", ps);
		 }
	}

	void Shader::Use()
	{
		if (mProgram)
		{
			glUseProgram(mProgram);
		}
	}

	void Shader::Reset()
	{
		mProgram = 0;
		mPs = 0;
		mVs = 0;
	}

	void Shader::Detach()
	{
		if (mProgram)
		{
			glDetachShader(mProgram, mVs);
			glDetachShader(mProgram, mPs);
			glDeleteProgram(mProgram);
			glDeleteShader(mVs);
			glDeleteShader(mPs);
			Reset();
		}
		if (mVs)
		{
			glDeleteShader(mVs);
		}
		if (mPs)
		{
			glDeleteShader(mPs);
		}
		Reset();
	}

};
