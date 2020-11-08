#pragma once
#include "en_def.h"
#include "en_verticies.h"
#include "en_indices.h"

namespace Engine
{
	struct Polygon
	{
	public:
		Verticies* verticies = nullptr;
		Indices* indices = nullptr;

	public:
		Polygon();
		Polygon(Verticies* verticies, Indices* indices);

	public:
		void ClearMemory();
	};
}