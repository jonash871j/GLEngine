#pragma once

namespace Engine
{
	class Math
	{
	public:
		static float Pow(float x, float y);
		static float Sqrt(float x);

		static float Sin(float x);
		static float Cos(float x);
		static float Tan(float x);
		static float Sec(float x);
		static float Cot(float x);
		static float Csc(float x);

		static float ASin(float x);
		static float ACos(float x);
		static float ATan(float x);

		static float Log(float x);

		static float Abs(float x);
		static float Floor(float x);
		static float Ceil(float x);
		static float Sign(float x);

		static const float PI;
	};
}