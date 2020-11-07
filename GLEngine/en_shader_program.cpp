#include "en_shader_program.h"
#include "en_console.h"
#include "en_window.h"

#include <GL/glew.h>
#include <stdlib.h>

namespace Engine
{
	ShaderProgram::ShaderProgram()
	{
		if (!Window::GetIsGLEWInitialized())
		{
			Console::PrintError("GLEW was not initialized", id);
			Console::PrintReason("No window was created", id);
			abort();
		}

		GL_CALL(id = glCreateProgram());
		Console::PrintSuccess("Created shader program: %d", id);
	}
	void ShaderProgram::Link()
	{
		int32_t success;

		GL_CALL(glLinkProgram(id));
		GL_CALL(glGetProgramiv(id, GL_LINK_STATUS, &success));

		if (!success)
		{
			char infoLog[1024]{ 0 };
			GL_CALL(glGetProgramInfoLog(id, 1024, NULL, infoLog));

			Console::PrintError("Couldn't link shader program: %i", id);
			Console::PrintReason("Following linker errors...");
			Console::PrintBuffer(infoLog, 1024);
			return;
		}
		
		GL_CALL(glUseProgram(NULL));
	}
	uint32_t& ShaderProgram::GetId()
	{
		return id;
	}
}
