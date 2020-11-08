#pragma once
#include "en_def.h"
#include "en_mesh.h"
#include "en_shader_program.h"
#include "en_texture.h"

namespace Engine
{
	class Renderer
	{
		friend class Window;
	private:
		Window* window = nullptr;
		float w = 0;
		float h = 0;
		struct c
		{
			uint8_t r;
			uint8_t g;
			uint8_t b;
			uint8_t a;
		}c = { 0, 0, 0, 0 };

	private:
		Renderer();

	private:
		void UpdateProperties(Window* window);

	public:
		void Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
		void Background();
		void Line(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
		void Line(float x1, float y1, float x2, float y2);
	
	public:
		void Mesh(Mesh* mesh, ShaderProgram* shaderProgram = nullptr, Texture* texture = nullptr);

	public:
		void Update();
		void Clear();
	};
}