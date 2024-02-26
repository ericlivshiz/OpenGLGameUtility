#pragma once

#include "../Utility/Window.h"

class Keyboard {
public:
	void Process_KeyInput(GLFWwindow* window);
public:
	bool ESC_PRESS = false;
	bool W_PRESS = false;
	bool A_PRESS = false;
	bool S_PRESS = false;
	bool D_PRESS = false;
	
	bool W_RELEASE = false;
	bool A_RELEASE = false;
	bool S_RELEASE = false;
	bool D_RELEASE = false;

};