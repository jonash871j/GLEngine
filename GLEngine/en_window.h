#pragma once
#include "en_def.h"
#include "en_renderer.h"
#include "en_input.h"
#include "en_time.h"

namespace Engine
{
	class Window
	{ 
		friend class Renderer;
		friend class Input;
	private:
		uint16_t width = 800, height = 600;
		uint8_t xScale = 1, yScale = 1;
		const char* title = "Program";

	private:
		bool isClosed = false;

	private:
		Renderer renderer;
		Input input;
		Time time;

	private:
		GLFWwindow* glfwWindow = nullptr;

	public:
		Window(uint16_t width, uint16_t height, const char* title);
		~Window();

	public:
		void UpdateEvents();
		void UpdateRenderer();
		void UpdateInput();
		void UpdateTime();
		void Update();

	public:
		void Target();
		void Close();

	public:
		void SetScaling(uint8_t xScale, uint8_t yScale);

	public:
		static bool GetIsGLEWInitialized();
		bool GetIsClosed();

		uint16_t GetWidth();
		uint16_t GetHeight();
		uint16_t GetActualWidth();
		uint16_t GetActualHeight();
		uint8_t GetXScale();
		uint8_t GetYScale();

		Renderer& GetRenderer();
		Input& GetInput();
		Time& GetTime();
		GLFWwindow* GetGLFWWindow();
	};
}


