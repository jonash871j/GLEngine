#include "en_verticies.h"

namespace Engine
{
	Verticies::Verticies()
	{
	}
	Verticies::Verticies(Vertex* values, uint32_t length)
		: values(values), length(length), size(length * sizeof(Vertex))
	{
	}
	Verticies::~Verticies()
	{
		if (values)
			delete[] values;
	}
}
