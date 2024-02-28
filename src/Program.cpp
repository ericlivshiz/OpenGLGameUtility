#include "Program.h"

Program::Program()
	:
	window{ SCR_WIDTH, SCR_HEIGHT},
	renderer{window},
	mouse{camera, window, MOUSE_SENSITIVITY},
	camera{glm::vec3(0.0f, PLAYER_HEIGHT, 3.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f},
	player{PLAYER_HEIGHT, PLAYER_SPEED, PLAYER_SHIFT_SPEED, PLAYER_CROUCH_SPEED}
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
		float Current_Frame = static_cast<float>(glfwGetTime());
		Delta_Time = Current_Frame - Last_Frame;
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
	if (keyboard.W_PRESS || keyboard.A_PRESS || keyboard.S_PRESS || keyboard.D_PRESS)
		player.Moving = true;

	if (keyboard.L_CTRL_PRESS)
	{
		player.Crouched = true;
	}

	if (!keyboard.L_CTRL_PRESS)
	{
		player.Crouched = false;
	}

	if (keyboard.L_SHIFT_PRESS)
	{
		player.ShiftWalking = true;
	}

	if (!keyboard.L_SHIFT_PRESS)
	{
		player.ShiftWalking = false;
	}

	if (keyboard.SPACE_PRESS)
	{
		player.Jumping = true;
	}

	if (!keyboard.SPACE_PRESS)
	{
		player.Jumping = false;
	}
}