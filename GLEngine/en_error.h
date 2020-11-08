#pragma once

#define ASSERT(x) if ((!x))	__debugbreak();


#define GL_CALL(x)										 \
		Core::GLLogClearError();						 \
		x ; 											 \
		ASSERT(Core::GLLogCall(#x, __FILE__, __LINE__))	 \

#define GLFW_CALL(x)									 \
		x ; 											 \
		ASSERT(Core::GLFWLogCall(#x, __FILE__, __LINE__))\

#ifndef NDEBUG
#define D_CALL(x) x;
#define DGL_CALL(x) GL_CALL(x)
#define DGLFW_CALL(x) GLFW_CALL(x)
#else
#define D_CALL(x) 
#define DGL_CALL(x)
#define DGLFW_CALL(x)
#endif