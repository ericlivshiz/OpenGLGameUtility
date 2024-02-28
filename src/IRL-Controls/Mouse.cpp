#include "Mouse.h"

Mouse* Mouse::instance = nullptr; // Initialize the static pointer

Mouse::Mouse(Camera& camera, Window& window, const float SENSITIVITY)
	:
	camera{camera},
	window{ window },
	SENSITIVITY{ SENSITIVITY }
{
	// Set the static instance poitner to this isntance
	instance = this;
	glfwSetCursorPosCallback(window.Get_Window(), Mouse_Callback);
	glfwSetScrollCallback(window.Get_Window(), Scroll_Callback);
	glfwSetInputMode(window.Get_Window(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Mouse::Mouse_Callback(GLFWwindow* window, double xPosIn, double yPosIn)
{
	// Access instance through static pointer
	if (instance)
	{
		float xpos = static_cast<float>(xPosIn);
		float ypos = static_cast<float>(yPosIn);

		if (instance->firstMouse)
		{
			instance->lastX = xpos;
			instance->lastY = ypos;
			instance->firstMouse = false;
		}

		float xoffset = xpos - instance->lastX;
		float yoffset = instance->lastY - ypos;

		instance->lastX = xpos;
		instance->lastY = ypos;

		instance->Process_MouseMovement(window, xoffset, yoffset, true);
	}

}

void Mouse::Process_MouseMovement(GLFWwindow* window, float xoffset, float yoffset, GLboolean constrainPitch)
{
	xoffset *= SENSITIVITY;
	yoffset *= SENSITIVITY;

	camera.Yaw += xoffset;
	camera.Pitch += yoffset;

	// make sure that when pitch is out of bounds, screen doesn't get flipped
	
	if (constrainPitch)
	{
		if (camera.Pitch > 89.0f)
			camera.Pitch = 89.0f;
		if (camera.Pitch < -89.0f)
			camera.Pitch = -89.0f;
	}
	

	camera.Update_CameraVectors();
}

void Mouse::Scroll_Callback(GLFWwindow* window, double xoffset, double yoffset)
{
	if (instance)
	{
		instance->Process_Scroll(static_cast<float>(yoffset));
	}
}

void Mouse::Process_Scroll(float yoffset)
{
	camera.Zoom -= (float)yoffset;
	if (camera.Zoom < 1.0f)
		camera.Zoom = 1.0f;
	if (camera.Zoom > 45.0f)
		camera.Zoom = 45.0f;
}