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
		uint16_t width, height;

	public:
		Sprite(Texture* texture);  
		Sprite(Texture* texture, uint16_t width, uint16_t height);
		Sprite(Texture* texture, uint16_t width, uint16_t height, uint16_t xSheetPos, uint16_t ySheetPos = 0);
		~Sprite();

	public:
		void SetSheetPosition(uint16_t xSheetPos, uint16_t ySheetPos = 0);

	public:
		float GetWidth();
		float GetHeight();
	};
}
