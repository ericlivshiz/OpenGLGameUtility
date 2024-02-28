#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Utility/Window.h"

// An abstract camera class that processes input and calculates the corresponding
// Euler Angles, Vectors, and Matrices for use in OpenGL
class Camera
{
public:
	// Constructor with vectors
	Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch);

	// Consructor with scalar values
	Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);

	glm::mat4 Get_ViewMatrix();

	void Update_CameraVectors();

public:
	// Euler Angles
	float Yaw;
	float Pitch;

	// Camera Options
	float Zoom;

	// Cam Atrributes
	glm::vec3 Position;
	glm::vec3 Front;
	glm::vec3 Up;
	glm::vec3 Right;
	glm::vec3 WorldUp;

private:

	static constexpr float STARTING_YAW{ -90.0f };
	static constexpr float STARTING_PITCH{ 0.0f };
	static constexpr float STARTING_ZOOM{ 45.0f };
};