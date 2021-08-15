#pragma once
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include "shader.h"

namespace AEngine
{

class Window
{
private:
	const char* m_Title;
	int m_Height, m_Width;
	GLFWwindow *m_Window;
	bool m_Closed;
	bool m_Init = false;

public:
	Window(const char* name, int width, int height);
	~Window();
	void Clear();
	void Update();
	bool Closed();
	void ProcessInput();
	void Display();

	inline int GetWidth() { return m_Width; }
	inline int GetHeight() { return m_Height; }

private:
	bool Init();
};

};
