#pragma once
#include <stdint.h>
#include <universal_string.h>

#include "en_console.h"
#include "en_core.h"



#define ASSERT(x) if ((!x))	__debugbreak();


#define GL_CALL(x)										 \
		Core::GLLogClearError();						 \
		x ; 											 \
		ASSERT(Core::GLLogCall(#x, __FILE__, __LINE__))	 \

#define GLFW_CALL(x)									 \
		x ; 											 \
		ASSERT(Core::GLFWLogCall(#x, __FILE__, __LINE__))\
