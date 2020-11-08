#pragma once
#include "en_def.h"
#include "en_verticies.h"
#include "en_indices.h"

namespace Engine
{
	struct Primitive
	{
	public:
		Verticies* verticies = nullptr;
		Indices* indicies = nullptr;

	public:
		Primitive(Verticies* verticies, Indices* indicies);

	public:
		static Primitive CreateTriangle(Vector3D color = { 255, 255, 255 });
		static Primitive CreateSquare(Vector3D color = { 255, 255, 255 });
	};
}
