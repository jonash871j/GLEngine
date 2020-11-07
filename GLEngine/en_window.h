#pragma once
#include "en_def.h"
#include "en_renderer.h"

struct GLFWwindow;

namespace Engine
{
	class Window
	{ 
		friend class Renderer;
	private:
		uint16_t width = 800;
		uint16_t height = 600;
		const char* title = "Program";

	private:
		bool isClosed = false;

	private:
		Renderer renderer;

	private:
		GLFWwindow* glWindow = nullptr;

	public:
		Window(uint16_t width, uint16_t height, const char* title);
		~Window();

	public:
		void UpdateEvents();
		void UpdateRenderer();
		void Update();

	public:
		void Target();

	public:
		static bool GetIsGLEWInitialized();
		bool GetIsClosed();


		Renderer& GetRenderer();
	};
}


