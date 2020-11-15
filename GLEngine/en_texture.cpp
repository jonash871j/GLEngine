#include "en_texture.h"
#include <GL/glew.h>
#include <iostream>

namespace Engine
{
	Texture::Texture(const char* path, Texture::Mode mode)
	{
		Image image(path);
		width = image.GetWidth();
		height = image.GetHeight();

		GL_CALL(glGenTextures(1, &id));
		GL_CALL(glBindTexture(GL_TEXTURE_2D, id));

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, (float)mode);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, (float)mode);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, (uint32_t)mode);


		GL_CALL(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.GetWidth(), image.GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.GetPixels()));

	}
	Texture::~Texture()
	{
		glDeleteTextures(1, &this->id);
	}
	uint16_t Texture::GetWidth()
	{
		return width;
	}
	uint16_t Texture::GetHeight()
	{
		return height;
	}
	uint32_t Texture::GetId()
	{
		return id;
	}
}
