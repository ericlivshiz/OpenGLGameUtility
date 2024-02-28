#pragma once

#include "../Utility/Window.h"
#include "../Camera.h"

class Mouse
{
public:
	Mouse(Camera& camera, Window& window, const float SENSITIVITY);
	const float SENSITIVITY;

private:
	static void Mouse_Callback(GLFWwindow* window, double xPosIn, double yPosIn);
	void        Process_MouseMovement(GLFWwindow* window, float xoffset, float yoffset, GLboolean constrainPitch = true);
	static void Scroll_Callback(GLFWwindow* window, double xoffset, double yoffset);
	void        Process_Scroll(float yoffset);

private:
	Camera& camera;
	Window& window;
	static Mouse* instance; // Static pointer to the instance of Mouse

	bool firstMouse;
	float lastX = static_cast<float>(window.Get_Width() / 2);
	float lastY = static_cast<float>(window.Get_Height() / 2);
};