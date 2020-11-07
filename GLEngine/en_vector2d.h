#pragma once
#include "en_def.h"

namespace Engine
{
	struct Vector2D
	{
	public:
		float x, y;

	public:
		Vector2D();
		Vector2D(float x, float y);
		Vector2D(int32_t x, int32_t y);
		Vector2D(const Vector2D& v);

	public:
		Vector2D  operator +  (const Vector2D& rhs);
		Vector2D  operator -  (const Vector2D& rhs);
		Vector2D  operator *  (const float& rhs);
		Vector2D  operator /  (const float& rhs);
		Vector2D& operator += (const Vector2D& rhs);
		Vector2D& operator -= (const Vector2D& rhs);
		Vector2D& operator *= (const float& rhs);
		Vector2D& operator /= (const float& rhs);
	};
}
