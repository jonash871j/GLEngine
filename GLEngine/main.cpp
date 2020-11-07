#include <iostream>
#include "engine.h"

using namespace Engine;

int main()
{
	// https://www.youtube.com/watch?v=oNNFazrxy6Q
	Core::Initialize();

	Window window(800, 600, "Program");
	Renderer& renderer = window.GetRenderer();

	ShaderProgram shaderProgram;
	Shader shaderFragment("fragment_core.shader", Shader::Type::Fragment, shaderProgram);
	Shader shaderCore("vertex_core.shader", Shader::Type::Vertex, shaderProgram);
	shaderProgram.Link();

	while (!window.GetIsClosed())
	{
		renderer.Clear();
		
		renderer.Color(0, 0, 32);
		renderer.Background();

		renderer.Color(255, 255, 255);
		//renderer.Line(32, rand() % 255, rand() % 255, 123);

		window.Update();
	}
}