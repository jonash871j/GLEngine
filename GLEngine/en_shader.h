#pragma once
#include "en_def.h"
#include "en_shader_program.h"

namespace Engine
{
	class Shader
	{
	public:
		enum class Type
		{
			Vertex = 0x8B31,
			Fragment = 0x8B30,
		};

	public:
		Shader();
		Shader(const char* path, Shader::Type type, ShaderProgram& program);
		~Shader();

	public:
		void LoadShader(const char* path, Shader::Type type, ShaderProgram& program);
	};
}
