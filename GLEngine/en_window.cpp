#include "en_window.h"
#include "en_core.h"

#include <GL/glew.h>
#include <glfw3.h>
#include <stdlib.h>

namespace Engine
{
	static bool isGlewInitialized = false;

	Window::Window(uint16_t width, uint16_t height, const char* title)
	{
		if (!Core::GetIsGLFWInitialized())
		{
			Console::PrintError("Window %s couldn't be created", title);
			Console::PrintReason("Core was not initalized");
			abort();
		}

		GLFW_CALL(glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE));
		GLFW_CALL(glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4));
		GLFW_CALL(glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4));
		GLFW_CALL(glfwWindowHint(GLFW_RESIZABLE, false));
		GLFW_CALL(glfwWindow = glfwCreateWindow(width, height, title, NULL, NULL));

		Target();
		if (glewInit() != GLEW_OK)
		{
			Console::PrintError("Couldn't initialize glewInit");
			abort();
		}
		isGlewInitialized = true;

		// Gl options
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
		glEnable(GL_BLEND);
		glCullFace(GL_BACK);
		glFrontFace(GL_CCW);
		glBlendFunc(GL_SRC0_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		renderer.UpdateProperties(this);
		input.UpdateProperties(this);

		Console::PrintSuccess("Window was created as %s", title);
		Console::PrintMsg("Dimensions %ix%i", width, height);
		Console::PrintMsg("OpenGL version: %s", glGetString(GL_VERSION));

		renderer.Clear();
		renderer.Color(32, 32, 32);
		renderer.Background();
		Update();
	}
	Window::~Window()
	{
		GLFW_CALL(glfwDestroyWindow(glfwWindow));
		GLFW_CALL(glfwTerminate());
	}

	void Window::UpdateEvents()
	{
		GLFW_CALL(glfwPollEvents());

		if (!isClosed)
			GLFW_CALL(isClosed = glfwWindowShouldClose(glfwWindow));

		if (isClosed)
			Console::PrintMsg("Window is closing...");
	}
	void Window::UpdateRenderer()
	{
		renderer.Update();
		renderer.Clear();
	}
	void Window::UpdateInput()
	{
		input.Update();
	}
	void Window::UpdateTime()
	{
		time.Update();
	}
	void Window::Update()
	{
		UpdateRenderer();
		UpdateEvents();
		UpdateInput();
		UpdateTime();
	}

	void Window::Target()
	{
		GLFW_CALL(glfwMakeContextCurrent(glfwWindow));
	}

	void Window::Close()
	{
		isClosed = true;
	}

	bool Window::GetIsGLEWInitialized()
	{
		return isGlewInitialized;
	}

	bool Window::GetIsClosed()
	{
		return isClosed;
	}
	Renderer& Window::GetRenderer()
	{
		return renderer;
	}
	Input& Window::GetInput()
	{
		return input;
	}
	Time& Window::GetTime()
	{
		return time;
	}
	GLFWwindow* Window::GetGLFWWindow()
	{
		return glfwWindow;
	}
}

