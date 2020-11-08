#include "en_square.h"

namespace Engine
{
	Square::Square()
	{
		Vertex* verticies = new Vertex[4]
		{
			Vertex({-0.5f, 0.5f, 0.0f },{ 1.0f, 0.0f, 0.0f }, { 0.0f, 1.0f }),
			Vertex({-0.5f,-0.5f, 0.0f },{ 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f }),
			Vertex({ 0.5f,-0.5f, 0.0f },{ 0.0f, 0.0f, 1.0f }, { 1.0f, 0.0f }),
			Vertex({ 0.5f, 0.5f, 0.0f },{ 1.0f, 1.0f, 0.0f }, { 1.0f, 1.0f }),
		};
		this->verticies = new Verticies(verticies, 4);

		uint32_t* indices = new uint32_t[6]
		{
			0, 1, 2,
			0, 2, 3
		};
		this->indices = new Indices(indices, 6);
	}

	Square::~Square()
	{
		ClearMemory();
	}
}