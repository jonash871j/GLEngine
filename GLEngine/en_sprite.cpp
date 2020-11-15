#include "en_sprite.h"

namespace Engine
{
	Sprite::Sprite(Texture* texture)
	{
		this->texture = texture;
		width = texture->GetWidth();
		height = texture->GetHeight();

		primitive = Primitive::CreateSquare();
		mesh = new Mesh(primitive);
	}
	Sprite::Sprite(Texture* texture, uint16_t width, uint16_t height)
		: Sprite(texture)
	{
		this->width = width;
		this->height = height;
	}
	Sprite::Sprite(Texture* texture, uint16_t width, uint16_t height, uint16_t xSheetPos, uint16_t ySheetPos)
	{
		this->texture = texture;
		this->width = width;
		this->height = height;

		uint16_t widthSheet = texture->GetWidth();
		uint16_t heightSheet = texture->GetHeight();

		primitive = Primitive::CreateSquare();

		primitive.verticies->values[2].texCoord.x = 1.0f / float(widthSheet / width);
		primitive.verticies->values[3].texCoord.x = 1.0f / float(widthSheet / width);

		mesh = new Mesh(primitive);
	}
	Sprite::~Sprite()
	{
		delete mesh;
	}
	void Sprite::SetSheetPosition(uint16_t xSheetPos, uint16_t ySheetPos)
	{
	}
	float Sprite::GetWidth()
	{
		return width;
	}
	float Sprite::GetHeight()
	{
		return height;
	}
}

