#pragma once
#include "en_def.h"

namespace Engine
{
	class Window;

	class Renderer
	{
		friend class Window;
	private:
		Window* window;
		float w;
		float h;
		struct c
		{
			uint8_t r;
			uint8_t g;
			uint8_t b;
			uint8_t a;
		}c;

	private:
		void UpdateProperties(Window* window);

	public:
		void Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
		void Background();
		void Line(float x1, float y1, float x2, float y2);

	public:
		void Target();
		void Update();
		void Clear();
	};
}