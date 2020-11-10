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
		Texture* texture = nullptr;
		Mesh* mesh = nullptr;
		Primitive primitive;
		
	private:
		float width;
		float height;

	public:
		Sprite(const char* path);
		Sprite(const char* path, float width, float height);
		~Sprite();

	public:
		float GetWidth();
		float GetHeight();
	};
}
