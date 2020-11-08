#include "en_image.h"

#include <SOIL2.h>

namespace Engine
{
	Image::Image()
	{
	}
	Image::Image(const char* path)
	{
		Load(path);
	}
	Image::~Image()
	{
		ClearMemory();
	}
	void Image::ClearMemory()
	{
		if (pixels)
			SOIL_free_image_data(pixels);
	}
	void Image::Load(const char* path)
	{
		// Loads image
		int32_t width = 0;
		int32_t height = 0;
		uint8_t* pixels = SOIL_load_image(path, &width, &height, nullptr, SOIL_LOAD_RGBA);
		
		// Checks if image is loaded correctly
		if (pixels == nullptr)
		{
			Console::PrintError("Failed to load image: %s", path);
			Console::PrintReason("Invalid path or unsupported format.");
			return;
		}

		// Clears old image data
		ClearMemory();

		// Sets image data
		this->width = width;
		this->height = height;
		this->pixels = pixels;
		this->path = path;

		Console::PrintSuccess("Image %s was loaded", path);
	}
	int32_t Image::GetWidth()
	{
		return width;
	}
	int32_t Image::GetHeight()
	{
		return height;
	}
	uint8_t* Image::GetPixels()
	{
		return pixels;
	}
};

