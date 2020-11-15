#pragma once
#include "en_def.h"

namespace Engine
{
	class ShaderProgram
	{
	private:
		uint32_t id;
		bool isLinked = false;

	public:
		ShaderProgram();

	public:
		void Link();

	public:
		uint32_t& GetId();
		bool GetIsLinked();

	public:
		static ShaderProgram CreateSpriteProgram();
	};
}
