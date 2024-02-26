#pragma once

#include "../Utility/Window.h"

class Renderer
{
	// Constructor should contain window
public:
	Renderer();

	void Pre_Render();
	void Render();
	void Post_Render();
};