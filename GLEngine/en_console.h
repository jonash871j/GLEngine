#pragma once
#include "en_def.h"

namespace Engine
{
	class Console
	{
		friend class Core;
	private:
		static void Initalize();

	public:
		static void PrintError(const char* format, ...);
		static void PrintReason(const char* format, ...);
		static void PrintWarning(const char* format, ...);
		static void PrintSuccess(const char* format, ...);
		static void PrintBuffer(char* buffer, int32_t length);
		static void PrintMsg(const char* format, ...);

	public:
		static void GetBuffer();
	};
}
