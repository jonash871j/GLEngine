#include "en_vector2d.h"
#include <math.h>

namespace Engine
{
	Vector2D::Vector2D() 
		: x(0), y(0)
	{

	}
	Vector2D::Vector2D(float x, float y) 
		: x(x), y(y)
	{

	}
	Vector2D::Vector2D(int32_t x, int32_t y)
		: x((float)x), y((float)y)
	{

	}

	Vector2D::Vector2D(const Vector2D& v) : x(v.x), y(v.y){}

	Vector2D Vector2D::operator +  (const Vector2D& rhs) 
	{ 
		return Vector2D(this->x + rhs.x, this->y + rhs.y); 
	}
	Vector2D Vector2D::operator -  (const Vector2D& rhs) 
	{
		return Vector2D(this->x - rhs.x, this->y - rhs.y); 
	}
	Vector2D Vector2D::operator *  (const float& rhs)
	{
		return Vector2D(this->x * rhs, this->y * rhs); 
	}
	Vector2D Vector2D::operator /  (const float& rhs)
	{
		return Vector2D(this->x / rhs, this->y / rhs); 
	}
	Vector2D& Vector2D::operator += (const Vector2D& rhs) 
	{
		this->x += rhs.x; this->y += rhs.y; return *this; 
	}
	Vector2D& Vector2D::operator -= (const Vector2D& rhs) 
	{
		this->x -= rhs.x; this->y -= rhs.y; return *this; 
	}
	Vector2D& Vector2D::operator *= (const float& rhs)
	{
		this->x *= rhs; this->y *= rhs; return *this; 
	}
	Vector2D& Vector2D::operator /= (const float& rhs)
	{
		this->x /= rhs; this->y /= rhs; return *this; 
	}
}