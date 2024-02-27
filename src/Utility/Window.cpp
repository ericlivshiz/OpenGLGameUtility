#include "Window.h"

Window::Window(unsigned& screenWidth, unsigned& screenHeight)
{
	SCR_WIDTH = screenWidth;
	SCR_HEIGHT = screenHeight;

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "GAME::ENGINE 0.0.1", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, Framebuffer_Size_Callback);

}

GLFWwindow* Window::Get_Window() const
{
	return window;
}

unsigned Window::Get_Width()
{
	return SCR_WIDTH;
}

unsigned Window::Get_Height()
{
	return SCR_HEIGHT;
}

void Window::Close_Window()
{
	glfwSetWindowShouldClose(window, GLFW_TRUE);
}

// make sure the viewport matches the new window dimensions; note that width and 
// height will be significantly larger than specified on retina displays.
void Window::Framebuffer_Size_Callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

Window::~Window() {
	glfwDestroyWindow(window);
	glfwTerminate();
}