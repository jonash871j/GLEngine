#include "en_shader_program.h"
#include "en_shader.h"
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

	ShaderProgram ShaderProgram::CreateSpriteProgram()
	{
		ShaderProgram spriteProgram;

		Shader fragment(
			"#version 440\n"
			"in vec3 vs_position;"
			"in vec2 vs_texcoord;"
			"out vec4 fs_color;"
			"uniform sampler2D Texture;"
			"void main()"
			"{"
			"	fs_color = texture(Texture, vs_texcoord);"
			"}"
			, 
			"default_fragment_sprites", Shader::Type::Fragment, spriteProgram);

		Shader vertex(
			"#version 440\n"
			"layout(location = 0) in vec3 vertex_position;"
			"layout(location = 2) in vec2 vertex_texcoord;"
			"out vec3 vs_position;"
			"out vec2 vs_texcoord;"
			"uniform mat4 Matrix;"
			"void main()"
			"{"
			"	vs_texcoord = vec2(vertex_texcoord.x, vertex_texcoord.y * -1.0f);"
			"	gl_Position = Matrix * vec4(vertex_position, 1.0f);"
			"}"
			,
			"default_fragment_vertex", Shader::Type::Vertex, spriteProgram);
		spriteProgram.Link();

		return spriteProgram;
	}
}
