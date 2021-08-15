#include <memory>
#include <windows.h>
#include "window.h"
using AEngine::Window;


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	auto win = std::shared_ptr<Window>(new Window("AEngine",1136,640));
	while (!win->Closed())
	{
		win->Update();
	}

	return 0;
}