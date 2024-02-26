#pragma once

#include "Utility/Window.h"
#include "Utility/Renderer.h"
#include "IRL-Controls/Keyboard.h"

class Program
{
public:
	Program();
	void Start();
	void Stop();

private:
	void Program_Loop();
	void Handle_Input();
	void Update();
	void Display();

	bool Program_Running = false;
	unsigned SCR_WIDTH = 1920;
	unsigned SCR_HEIGHT = 1080;

private:
	Window window;
	Renderer renderer;
	Keyboard keyboard;
};