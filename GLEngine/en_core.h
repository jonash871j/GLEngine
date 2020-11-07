#pragma once
#include "en_def.h"

namespace Engine
{
	class Core
	{
	public:
		static void Initialize();

	public:
		static void GLLogClearError();
		static bool GLLogCall(const char* function, const char* file, int line);
		static bool GLFWLogCall(const char* function, const char* file, int line);

	public:
		static bool GetIsGLFWInitialized();
	};
}
