#include "Program.h"

Program::Program()
	:
	window{ SCR_WIDTH, SCR_HEIGHT},
	player{PLAYER_SPEED, PLAYER_SHIFT_SPEED, PLAYER_CROUCH_SPEED}
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
}

void Program::Update()
{
	glfwSwapBuffers(window.Get_Window());
	glfwPollEvents();

	Sync_PlayerAndKeyboard();
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

void Program::Sync_PlayerAndKeyboard()
{
	if (keyboard.A_PRESS || keyboard.D_PRESS || keyboard.S_PRESS || keyboard.W_PRESS)
		player.Moving = true;

	if (keyboard.L_CTRL_PRESS)
	{
		player.Crouched = true;
	}

	if (keyboard.L_CTRL_RELEASE)
	{
		player.Crouched = false;
	}

	if (keyboard.L_SHIFT_PRESS)
	{
		player.ShiftWalking = true;
	}

	if (keyboard.L_SHIFT_RELEASE)
	{
		player.ShiftWalking = false;
	}
}