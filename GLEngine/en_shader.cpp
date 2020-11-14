#include "en_shader.h"

#include <simple_file_handler.h>
#include <GL/glew.h>
#include <iostream>

namespace Engine
{
	Shader::Shader()
	{
	}
	Shader::Shader(const char* source, const char* name, Shader::Type type, ShaderProgram& program)
	{
		CreateShader(source, name, type, program);
	}
	Shader::Shader(const char* path, Shader::Type type, ShaderProgram& program)
	{
		LoadShader(path, type, program);
	}
	Shader::~Shader()
	{
	
	}

	void Shader::CreateShader(const char* source, const char* name, Shader::Type type, ShaderProgram& program)
	{
		int32_t success = 0;
		uint32_t shader = glCreateShader((int32_t)type);
		GL_CALL(glShaderSource(shader, 1, &source, NULL));
		GL_CALL(glCompileShader(shader));
		GL_CALL(glGetShaderiv(shader, GL_COMPILE_STATUS, &success));

		if (!success)
		{
			char infoLog[1024]{ 0 };
			GL_CALL(glGetShaderInfoLog(shader, 1024, NULL, infoLog));

			Console::PrintError("Failed to compile %s", name);
			Console::PrintReason("Following compiler errors: ");
			Console::PrintBuffer(infoLog, 1024);
		}
		else
		{
			GL_CALL(glAttachShader(program.GetId(), shader));
			Console::PrintSuccess("Shader %s was loaded and compiled", name);
		}

		// Clear memory
		GL_CALL(glDeleteShader(shader));
	}

	void Shader::LoadShader(const char* path, Shader::Type type, ShaderProgram& program)
	{
		char* source = nullptr;
		uint64_t size = sfh::FileMisc::GetFileSize(path);

		try
		{
			sfh::ReadFile inFile(path);
			source = inFile.ReadBuffer(size, true);
			inFile.Close();
		}
		catch (std::exception exception)
		{
			Console::PrintError("Couldn't load shader %s", path);
			Console::PrintReason(exception.what());
			return;
		}
		CreateShader(source, path, type, program);
	
		delete source;
	}
}
