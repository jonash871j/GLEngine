#include "en_texture.h"
#include <GL/glew.h>
#include <iostream>

namespace Engine
{
	Texture::Texture(const char* path)
	{
		Image image(path);
		width = image.GetWidth();
		height = image.GetHeight();

		GL_CALL(glGenTextures(1, &id));
		GL_CALL(glBindTexture(GL_TEXTURE_2D, id));

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		GL_CALL(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.GetWidth(), image.GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.GetPixels()));
		//GL_CALL(glGenerateMipmap(GL_TEXTURE_2D)); ???
	}
	Texture::~Texture()
	{
		glDeleteTextures(1, &this->id);
	}
}
