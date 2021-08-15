#pragma once
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"

namespace AEngine
{

class Shader
{
private:
	bool GetShaderState(GLuint obj);
	bool GetProgramState(GLuint obj);
	GLuint mVs;
	GLuint mPs;
	GLuint mProgram;
public:
	Shader();
	Shader(Shader&&);
	~Shader() { Detach(); }
	void CreateFromFile(const char*,const char*);
	void CreateFromStr(const char*,const char*);
	void Use();
	void Detach();
	void Reset();
	bool Ok() { return mProgram != 0; }
};

};
