#include "en_renderer.h"
#include "en_window.h"

#include <GL/glew.h>
#include <glfw3.h>

namespace Engine
{
	void Renderer::UpdateProperties(Window* window)
	{
		this->window = window;
		w = (float)window->width;
		h = (float)window->height;
	}

	void Renderer::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
	{
		c = { r, g, b, a };
		//glColor4b(r, g, b, a);
	}

	void Renderer::Background()
	{
		GL_CALL(glClearColor(0.003f * (float)c.r, 0.003f * (float)c.g, 0.003f * (float)c.b, 0.003f * (float)c.a));
	}

	void Renderer::Line(float x1, float y1, float x2, float y2)
	{
		x1 = 2.0f * x1 / w - 1.0f;
		y1 = 2.0f * y1 / h - 1.0f;
		x2 = 2.0f * x2 / w - 1.0f;
		y2 = 2.0f * y2 / h - 1.0f;

		GL_CALL(glBegin(GL_LINES));
		GL_CALL(glVertex2f(x1, y1));
		GL_CALL(glVertex2f(x2, y2));
		GL_CALL(glEnd());
	}
	void Renderer::Target()
	{
		GLFW_CALL(glfwMakeContextCurrent(window->glWindow));
	}
	void Renderer::Update()
	{
		GLFW_CALL(glfwSwapBuffers(window->glWindow));
		GL_CALL(glFlush());
	}
	void Renderer::Clear()
	{
		GL_CALL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT));
	}
}