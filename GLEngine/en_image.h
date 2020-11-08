#pragma once
#include "en_def.h"

namespace Engine
{
	class Image
	{
	private:
		const char* path = "null";
		int32_t width = 0;
		int32_t height = 0;
		uint8_t* pixels = nullptr;

	public:
		Image();
		Image(const char* path);
		~Image();

	private:
		void ClearMemory();

	public:
		void Load(const char* path);

	public:
		int32_t GetWidth();
		int32_t GetHeight();
		uint8_t* GetPixels();
	};
}