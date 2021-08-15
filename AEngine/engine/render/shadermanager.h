#pragma once
#include<unordered_map>
#include<memory>
#include"shader.h"

using std::unordered_map;
using std::string;
using std::shared_ptr;

namespace AEngine
{

class ShaderManager
{
private:
	unordered_map<string, shared_ptr<Shader>>mShaders;
	shared_ptr<Shader> CreateDeFaultShader();

public:
	ShaderManager();
	shared_ptr<Shader>CreateShaderFromFile(const char*, const char*);
	shared_ptr<Shader>CreateShaderFromStr(const char*, const char*);
	static ShaderManager& Instance();
	void Destroy();
	
};

};
