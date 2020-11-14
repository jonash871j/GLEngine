#pragma once
#include "en_def.h"
#include "en_mesh.h"
#include "en_shader_program.h"
#include "en_texture.h"
#include "en_sprite.h"

namespace Engine
{
	class Renderer
	{
		friend class Window;
	private:
		Window* window = nullptr;
		ShaderProgram* shaderProgram = nullptr;

	private:
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
		void Update();
		void Clear();

	public:
		void Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
		void Background();
		void Line(float x1, float y1, float x2, float y2);
		void Mesh(Mesh* mesh, Texture* texture = nullptr);
		void Sprite(Sprite* sprite, const Vector2D& position = { 0.0f, 0.0f }, float rotation = 0.0f, const Vector2D& size = { 1.0f, 1.0f });

	public:
		void SetShaderProgram(ShaderProgram* shaderProgram);
	};
}