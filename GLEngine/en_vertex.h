#pragma once
#include "en_def.h"
#include "en_vector2d.h"
#include "en_vector3d.h"

namespace Engine
{
	struct Vertex
	{
		Vector3D position;
		Vector3D color;
		Vector2D texCoord;

		Vertex(Vector3D position, Vector3D color, Vector2D texCoord);
	};
}


