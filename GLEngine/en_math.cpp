#include "en_math.h"
#include <math.h>

float Math::Pow(float x, float y)
{
	return powf(x, y);
}

float Math::Sqrt(float x)
{
	return sqrtf(x);
}

float Math::Sin(float x)
{
	return sinf(x);
}

float Math::Cos(float x)
{
	return cosf(x);
}

float Math::Tan(float x)
{
	return tanf(x);
}

float Math::Sec(float x)
{
	return 1 / cosf(x);
}

float Math::Cot(float x)
{
	return 1 / tanf(x);
}

float Math::Csc(float x)
{
	return 1 / sinf(x);
}

float Math::ASin(float x)
{
	return asinf(x);
}

float Math::ACos(float x)
{
	return acosf(x);
}

float Math::ATan(float x)
{
	return atanf(x);
}

float Math::Log(float x)
{
	return logf(x);
}

float Math::Abs(float x)
{
	return fabsf(x);
}

float Math::Floor(float x)
{
	return floorf(x);
}

float Math::Ceil(float x)
{
	return ceilf(x);
}

float Math::Sign(float x)
{
	if (x >= 1)		return  1.0f;
	if (x <= -1)	return -1.0f;
	else			return  0.0f;
}
