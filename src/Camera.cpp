#include "Camera.h"

Camera::Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
	float yaw = STARTING_YAW,
	float pitch = STARTING_PITCH)
	:
	Front(glm::vec3(0.0f, 0.0f, -1.0f)),
	Zoom{STARTING_ZOOM}
{
	Position = position;
	WorldUp = up;
	Yaw = yaw;
	Pitch = pitch;
}

Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch)
	:
	Front(glm::vec3(0.0f, 0.0f, -1.0f)),
	Zoom{ STARTING_ZOOM }
{
	Position = glm::vec3(posX, posY, posZ);
	WorldUp = glm::vec3(upX, upY, upZ);
	Yaw = yaw;
	Pitch = pitch;
}

glm::mat4 Camera::Get_ViewMatrix()
{
	return glm::lookAt(Position, Position + Front, Up);
}

void Camera::Update_CameraVectors()
{

	// Calculate the new Front, Right, and Up vector
	glm::vec3 front;
	front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	front.y = sin(glm::radians(Pitch));
	front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	Front = glm::normalize(front);

	Right = glm::normalize(glm::cross(Front, WorldUp));
	Up = glm::normalize(glm::cross(Right, Front));
}