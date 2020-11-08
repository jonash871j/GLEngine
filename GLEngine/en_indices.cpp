#include "en_indices.h"

namespace Engine
{
	Indices::Indices()
	{
	}
	Indices::Indices(uint32_t* values, uint32_t length)
		: values(values), length(length), size(length * sizeof(uint32_t))
	{
	}
	Indices::~Indices()
	{
		if (values)
			delete[] values;
	}
}
