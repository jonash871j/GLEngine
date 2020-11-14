#pragma once
#include "en_def.h"

namespace Engine
{
	class ShaderProgram
	{
	private:
		uint32_t id;

	public:
		ShaderProgram();

	public:
		void Link();

	public:
		uint32_t& GetId();

	public:
		static ShaderProgram CreateSpriteProgram();
	};
}
