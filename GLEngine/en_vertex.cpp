#include "en_vertex.h"

namespace Engine
{
	Vertex::Vertex(Vector3D position, Vector3D color, Vector2D texCoord, Vector3D normal)
		: position(position), color(color), texCoord(texCoord), normal(normal)
	{
	}
}

