#pragma once
#include "en_def.h"
#include "en_image.h"

namespace Engine
{
	class Texture
	{
	public:
		uint32_t width;
		uint32_t height;
		uint32_t id = 0;

	public:
		Texture(const char* path);
		~Texture();
	};
}
