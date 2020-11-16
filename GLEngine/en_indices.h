#pragma once
#include "en_def.h"

namespace Engine
{
	struct Indices
	{
	public:
		uint32_t* values = nullptr;
		uint32_t length = 0;
		uint32_t size = 0;

	public:
		Indices();
		Indices(uint32_t* values, uint32_t length);
		~Indices();

	public:
		uint32_t& operator[](int i);
	};
}