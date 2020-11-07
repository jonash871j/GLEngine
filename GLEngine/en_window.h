#pragma once
#include "en_def.h"
#include "en_renderer.h"
#include "en_input.h"

namespace Engine
{
	class Window
	{ 
		friend class Renderer;
		friend class Input;
	private:
		uint16_t width = 800;
		uint16_t height = 600;
		const char* title = "Program";

	private:
		bool isClosed = false;

	private:
		Renderer renderer;
		Input input;

	private:
		GLFWwindow* glfwWindow = nullptr;

	public:
		Window(uint16_t width, uint16_t height, const char* title);
		~Window();

	public:
		void UpdateEvents();
		void UpdateRenderer();
		void UpdateInput();
		void Update();

	public:
		void Target();
		void Close();

	public:
		static bool GetIsGLEWInitialized();
		bool GetIsClosed();
		Renderer& GetRenderer();
		Input& GetInput();
		GLFWwindow* GetGLFWWindow();
	};
}


