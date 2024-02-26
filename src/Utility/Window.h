#pragma once

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <iostream>

class Window
{

public:
	Window(unsigned& screenWidth, unsigned& screenHeight);
	GLFWwindow* Get_Window()const;
	unsigned Get_Width();
	unsigned Get_Height();
	void Close_Window();
	~Window();

public:
	unsigned SCR_WIDTH;
	unsigned SCR_HEIGHT;

private:
	GLFWwindow* window;
};