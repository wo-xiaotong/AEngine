#include"shadermanager.h"
#include<memory>

const char*SIMPLE_VS = "C:\\Users\\zt\\Desktop\\AEngine\\shader_source\\simple.vert";
const char*SIMPLE_PS = "C:\\Users\\zt\\Desktop\\AEngine\\shader_source\\simple.frag";


namespace AEngine 
{
	ShaderManager::ShaderManager()
	{
		auto s = CreateDeFaultShader();
		mShaders.emplace("Simple_Shader", s);
	}

	shared_ptr<Shader> ShaderManager::CreateDeFaultShader()
	{
		auto s = std::make_shared<Shader>();
		s->CreateFromFile(SIMPLE_VS, SIMPLE_PS);
		return s;
	}

	ShaderManager& ShaderManager::Instance()
	{
		static ShaderManager s;
		return s;
	}

	void ShaderManager::Destroy()
	{
		for (auto it = mShaders.begin();it != mShaders.end(); it++)
		{
			it->second->Detach();
		}
		mShaders.clear();
	}

	shared_ptr<Shader> ShaderManager::CreateShaderFromFile(const char*vs, const char*ps)
	{
		string key = string(vs);
		if (mShaders.find(key) != mShaders.end())
		{
			return mShaders[key];
		}
		auto s = std::make_shared<Shader>();
		s->CreateFromFile(vs, ps);
		if (s->Ok()) 
		{
			mShaders[key] = s;
			return s;
		}
		return mShaders["SimpeVert"];
	}

	shared_ptr<Shader> ShaderManager::CreateShaderFromStr(const char*, const char*)
	{
		return nullptr;
	}
}
