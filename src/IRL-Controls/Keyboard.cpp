#include "Keyboard.h"

void Keyboard::Process_KeyInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		ESC_PRESS = true;

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		W_PRESS = true;
		W_RELEASE = false;
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		A_PRESS = true;
		A_RELEASE = false;
	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		S_PRESS = true;
		S_RELEASE = false;
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		D_PRESS = true;
		D_RELEASE = false;
	}

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_RELEASE)
	{
		W_RELEASE = true;
		W_PRESS = false;
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_RELEASE)
	{
		A_RELEASE = true;
		A_PRESS = false;
	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_RELEASE)
	{
		S_RELEASE = true;
		S_PRESS = false;
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_RELEASE)
	{
		D_RELEASE = true;
		D_PRESS = false;
	}
}
