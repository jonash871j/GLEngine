#pragma once
#include "en_def.h"
#include "en_vertex.h"

namespace Engine
{
	struct Verticies
	{
	public:
		Vertex* values = nullptr;
		uint32_t length = 0;
		uint32_t size = 0;

	public:
		Verticies();
		Verticies(Vertex* values, uint32_t length);
		~Verticies();
	};
}