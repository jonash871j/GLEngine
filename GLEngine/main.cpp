#include <iostream>
#include "engine.h"
#include <GL/glew.h>

using namespace Engine;

int main()
{
	// https://www.youtube.com/watch?v=oNNFazrxy6Q
	Core::Initialize();

	Window window(800, 600, "Program");
	Renderer& renderer = window.GetRenderer();
	Input& input = window.GetInput();

	ShaderProgram coreProgram;
	Shader shaFragment("fragment_core.shader", Shader::Type::Fragment, coreProgram);
	Shader shaCore("vertex_core.shader", Shader::Type::Vertex, coreProgram);
	coreProgram.Link();


	while (!window.GetIsClosed())
	{
		renderer.Clear();
		
		if (input.KeyPressed(Key::Escape))
			window.Close();

		renderer.Color(32, 32, 64);
		renderer.Background();

		renderer.Color(255, 255, 255);
		renderer.Line(0.5f, 0.5f, 1.0f, 1.0f);

		glUseProgram(coreProgram.GetId());

		window.Update();
	}
}