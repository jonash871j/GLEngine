#include "en_sprite.h"

namespace Engine
{
	Sprite::Sprite(const char* path, ShaderProgram* shaderProgram)
	{
		this->texture = new Texture(path);

		this->primitive = Primitive::CreateSquare();
		this->mesh = new Mesh(primitive);

		this->shaderProgram = shaderProgram;
	}
	Sprite::~Sprite()
	{
		delete texture;
		delete mesh;
	}
}

