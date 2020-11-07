#include "en_vector3d.h"
#include <math.h>

namespace Engine
{
	Vector3D::Vector3D()
		: x(0), y(0), z(0)
	{

	}
	Vector3D::Vector3D(float x, float y, float z)
		: x(x), y(y), z(z)
	{

	}
	Vector3D::Vector3D(int32_t x, int32_t y, int32_t z)
		: x((float)x), y((float)y), z((float)z)
	{

	}

	Vector3D::Vector3D(const Vector3D& v) 
		: x(v.x), y(v.y), z(v.z)
	{}

	Vector3D Vector3D::operator +  (const Vector3D& rhs)
	{
		return Vector3D(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
	}
	Vector3D Vector3D::operator -  (const Vector3D& rhs)
	{
		return Vector3D(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
	}
	Vector3D Vector3D::operator *  (const float& rhs)
	{
		return Vector3D(this->x * rhs, this->y * rhs, this->z * rhs);
	}
	Vector3D Vector3D::operator /  (const float& rhs)
	{
		return Vector3D(this->x / rhs, this->y / rhs, this->z / rhs);
	}
	Vector3D& Vector3D::operator += (const Vector3D& rhs)
	{
		this->x += rhs.x; this->y += rhs.y; this->z += rhs.z; return *this;
	}
	Vector3D& Vector3D::operator -= (const Vector3D& rhs)
	{
		this->x -= rhs.x; this->y -= rhs.y; this->z -= rhs.z; return *this;
	}
	Vector3D& Vector3D::operator *= (const float& rhs)
	{
		this->x *= rhs; this->y *= rhs; this->z *= rhs; return *this;
	}
	Vector3D& Vector3D::operator /= (const float& rhs)
	{
		this->x /= rhs; this->y /= rhs; this->z /= rhs; return *this;
	}
}