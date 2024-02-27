#pragma once

#include "Utility/Window.h"
#include "Utility/Renderer.h"
#include "IRL-Controls/Keyboard.h"
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

	unsigned SCR_WIDTH = 1920;
	unsigned SCR_HEIGHT = 1080;

	// This is initialized here so the program can run
	// but it will belong to the game code in general
	const float PLAYER_SPEED = 50.0f;
	const float PLAYER_SHIFT_SPEED = 17.0f;
	const float PLAYER_CROUCH_SPEED = 10.0f;

private:
	Window window;
	Renderer renderer;
	Keyboard keyboard;
	Player player;
};
