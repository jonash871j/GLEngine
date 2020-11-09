#pragma once
#include "en_def.h"
#include "en_vector2d.h"
#include "en_image.h"
#include "en_texture.h"
#include "en_mesh.h"
#include "en_shader_program.h"

namespace Engine
{
	class Sprite
	{
		friend class Renderer;
	private:
		ShaderProgram* shaderProgram = nullptr;
		Texture* texture = nullptr;
		Mesh* mesh = nullptr;
		Primitive primitive;

	public:
		Sprite(const char* path, ShaderProgram* shaderProgram);
		~Sprite();
	};
}
