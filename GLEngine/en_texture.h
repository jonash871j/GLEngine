#pragma once
#include "en_def.h"
#include "en_image.h"

namespace Engine
{
	class Texture
	{
	public:
		enum class Mode
		{
			Nearest = 0x2600,
			Linear = 0x2601,
		};

	private:
		uint16_t width;
		uint16_t height;
		uint32_t id = 0;

	public:
		Texture(const char* path, Texture::Mode mode = Mode::Nearest);
		~Texture();

	public:
		uint16_t GetWidth();
		uint16_t GetHeight();
		uint32_t GetId();
	};
}
