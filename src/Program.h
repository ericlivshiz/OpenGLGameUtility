#pragma once

#include "Utility/Window.h"
#include "Utility/Renderer.h"
#include "IRL-Controls/Keyboard.h"
#include "IRL-Controls/Mouse.h"
#include "Camera.h"
#include "Player.h"

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

private:
	void Sync_PlayerAndKeyboard();

	bool Program_Running = false;

	// These will be handled by the UI later instead of being hard-coded
	
	// Window Constructor
	unsigned SCR_WIDTH = 1920;
	unsigned SCR_HEIGHT = 1080;

	// Mouse Constructor
	const float MOUSE_SENSITIVITY = 0.03f;

	// Player Constructor
	const float PLAYER_HEIGHT = 8.5f;
	const float PLAYER_SPEED = 50.0f;
	const float PLAYER_SHIFT_SPEED = 17.0f;
	const float PLAYER_CROUCH_SPEED = 10.0f;

	// Timing
	float Delta_Time = 0.0f;
	float Last_Frame = 0.0f;

private:
	Window window;
	Renderer renderer;
	Mouse mouse;
	Keyboard keyboard;
	Camera camera;
	Player player;

	
};