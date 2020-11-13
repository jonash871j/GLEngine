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
	Time& time = window.GetTime();

	ShaderProgram coreProgram;
	Shader shaFragment("fragment_core.shader", Shader::Type::Fragment, coreProgram);
	Shader shaCore("vertex_core.shader", Shader::Type::Vertex, coreProgram);
	coreProgram.Link(); 
	renderer.SetShaderProgram(&coreProgram);

	Sprite sprite("Images/Alien.png", 64, 64);

	Vector2D vector;

	while (!window.GetIsClosed())
	{
		if (input.KeyPressed(Key::Escape))
			window.Close();

		vector.x += (input.KeyState(Key::D) - input.KeyState(Key::A)) * time.GetDeltaTime() * 100.0f;
		vector.y += (input.KeyState(Key::S) - input.KeyState(Key::W)) * time.GetDeltaTime() * 100.0f;

		renderer.Background();

		renderer.Sprite(&sprite, vector);


		Console::PrintMsg("X: %f Y: %f", vector.x, vector.y);


		window.Update();
		//glBindVertexArray(0);
		//glUseProgram(0);
		//glActiveTexture(0);
		//glBindTexture(GL_TEXTURE_2D, 0);
	}
	Core::Unitialize();
}