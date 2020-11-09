#include "en_sprite.h"

namespace Engine
{
	Sprite::Sprite(const char* path)
	{
		texture = new Texture(path);
		width = (float)texture->width;
		height = (float)texture->height;

		primitive = Primitive::CreateSquare();
		mesh = new Mesh(primitive);
	}
	Sprite::Sprite(const char* path, float width, float height)
		: Sprite(path)
	{
		this->width = width;
		this->height = height;
	}
	Sprite::~Sprite()
	{
		delete texture;
		delete mesh;
	}
}

