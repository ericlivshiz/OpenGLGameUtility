#include "Renderer.h"

Renderer::Renderer(Window& window)
	:
	window{window}
{

}

void Renderer::Pre_Render()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Render()
{
	// Call window.draw as needed with objects
}

void Renderer::Post_Render()
{
	// call window.display
}