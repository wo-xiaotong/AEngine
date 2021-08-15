#include "window.h"
#include "utils\logtool.h"
#include "shadermanager.h"


namespace AEngine
{
	Window::Window(const char* title, int width, int height) :
		m_Title(title),m_Width(width),m_Height(height),m_Window(NULL),m_Closed(false)
	{
		m_Init = Init();
		LogTool::Instance().LogInfo("AEngine window init = %d", m_Init);
	}

	bool Window::Init()
	{
		if (!glfwInit())
		{
			return false;
		}
		
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (m_Window == NULL)
		{
			return false;
		}
		glfwMakeContextCurrent(m_Window);

		if (glewInit() != GLEW_OK)
		{
			return false;
		}

		glViewport(0, 0, m_Width, m_Height);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glfwSwapInterval(1);


		return true;
	}

	bool Window::Closed()
	{
		return glfwWindowShouldClose(m_Window);
	}

	void Window::Update()
	{
		if (!m_Init)return;
		ProcessInput();
		Clear();
		Display();
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	void Window::Display()
	{
		auto s = AEngine::ShaderManager::Instance().CreateShaderFromFile("C:\\Users\\zt\\Desktop\\AEngine\\shader_source\\simple.vert", "C:\\Users\\zt\\Desktop\\AEngine\\shader_source\\simple.frag");
		s->Use();
	}

	void Window::ProcessInput()
	{
		if (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS) 
		{
			glfwSetWindowShouldClose(m_Window, true);
		}
	}

	void Window::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	Window::~Window()
	{
		if (!m_Closed)
		{
			glfwDestroyWindow(m_Window);
			m_Window = nullptr;
			glfwTerminate();
			m_Closed = true;
		}
	}

};
