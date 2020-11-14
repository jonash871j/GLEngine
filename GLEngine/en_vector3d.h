#pragma once
#include "en_def.h"
#include "en_vector2d.h"

namespace Engine
{
	struct Vector3D
	{
	public:
		float x, y, z;

	public:
		Vector3D();
		Vector3D(float x, float y, float z);
		Vector3D(int32_t x, int32_t y, int32_t z);
		Vector3D(const Vector2D& v);
		Vector3D(const Vector3D& v);

	public:
		Vector3D  operator +  (const Vector3D& rhs);
		Vector3D  operator -  (const Vector3D& rhs);
		Vector3D  operator *  (const float& rhs);
		Vector3D  operator /  (const float& rhs);
		Vector3D& operator += (const Vector3D& rhs);
		Vector3D& operator -= (const Vector3D& rhs);
		Vector3D& operator *= (const float& rhs);
		Vector3D& operator /= (const float& rhs);
	};
}