#include "en_core.h"

#include <GL/glew.h>
#include <glfw3.h>

namespace Engine
{
	static bool isInitialized = false;

	void Core::Initialize()
	{
		// Initalizes console
		Console::Initalize();

		// Initializes GLFW
		GLFW_CALL(glfwInit());

		Console::PrintSuccess("GLFW was initialized");
		
		isInitialized = true;
	}
	void Core::GLLogClearError()
	{
		while (glGetError() != GL_NO_ERROR);
	}
	bool Core::GLLogCall(const char* function, const char* file, int line)
	{
		while (GLenum error = glGetError())
		{
			Console::PrintError("GLEW failure file %s -> function %s -> line %i", "N/A", function, line);
			Console::PrintReason("%s", glewGetErrorString(error));
			abort();
			return false;
		}
		return true;
	}
	bool Core::GLFWLogCall(const char* function, const char* file, int line)
	{
		const char* error = NULL;
		glfwGetError(&error);

		if (error != NULL)
		{
			Console::PrintError("GLFW failure file %s -> %s on line %i", "N/A", function, line);
			Console::PrintReason("%s", error);
			abort();
			return false;
		}

		return true;
	}
	bool Core::GetIsGLFWInitialized()
	{
		return isInitialized;
	}
}
