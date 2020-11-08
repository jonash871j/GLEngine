#include "en_polygon.h"

namespace Engine
{
	Polygon::Polygon()
	{
	}
	Polygon::Polygon(Verticies* verticies, Indices* indices)
		: verticies(verticies), indices(indices)
	{
	}
	void Polygon::ClearMemory()
	{
		if (verticies)
			delete verticies;
		if (indices)
			delete indices;
	}
}
