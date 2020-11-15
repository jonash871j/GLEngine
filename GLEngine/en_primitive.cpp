#include "en_primitive.h"

namespace Engine
{
	Primitive::Primitive()
	{
	}
	Primitive::Primitive(Verticies* verticies, Indices* indicies)
		: verticies(verticies), indicies(indicies)
	{
	}
	Primitive Primitive::CreateTriangle(Vector3D color)
	{
		Vertex* verticies = new Vertex[]
		{
			Vertex({-1.0f, 1.0f, 0.0f }, color, { 0.0f, 1.0f }),
			Vertex({-1.0f,-1.0f, 0.0f }, color, { 0.0f, 0.0f }),
			Vertex({ 1.0f,-1.0f, 0.0f }, color, { 1.0f, 0.0f }),
		};
		uint32_t* indices = new uint32_t[]
		{
			0, 1, 2,
		};
		return Primitive(new Verticies(verticies, 3), new Indices(indices, 3));
	}
	Primitive Primitive::CreateSquare(Vector3D color)
	{  
		Vertex* verticies = new Vertex[]
		{
			Vertex({-1.0f, 1.0f, 0.0f }, color, { 0.0f, 1.0f }),
			Vertex({-1.0f,-1.0f, 0.0f }, color, { 0.0f, 0.0f }),
			Vertex({ 1.0f,-1.0f, 0.0f }, color, { 1.0f, 0.0f }),
			Vertex({ 1.0f, 1.0f, 0.0f }, color, { 1.0f, 1.0f }),
		};
		uint32_t* indices = new uint32_t[]
		{
			0, 1, 2,
			0, 2, 3
		};
		return Primitive(new Verticies(verticies, 4), new Indices(indices, 6));
	}
}
