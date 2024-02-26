#include "Program.h"

Program::Program()
	:
	window{ SCR_WIDTH, SCR_HEIGHT}
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}
}

void Program::Start()
{
	Program_Running = true;
	Program_Loop();
}

void Program::Program_Loop()
{
	while (!glfwWindowShouldClose(window.Get_Window()))
	{
		Handle_Input();
		Update();
		Display();
	}
}

void Program::Handle_Input()
{
	keyboard.Process_KeyInput(window.Get_Window());

	if (keyboard.ESC_PRESS)
		window.Close_Window();

	glfwPollEvents();
}

void Program::Update()
{
	// Call functions that update something every frame
}

void Program::Display()
{
	renderer.Pre_Render();

	renderer.Render();

	renderer.Post_Render();
}

void Program::Stop()
{
	Program_Running = false;
}