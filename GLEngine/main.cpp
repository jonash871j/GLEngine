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

	Vector2D position;
	Vector2D size = { 1.0f, 1.0f };
	float rotation = 0.0f;

	while (!window.GetIsClosed())
	{
		if (input.KeyPressed(Key::Escape))
			window.Close();

		position.x += (input.KeyState(Key::D) - input.KeyState(Key::A)) * time.GetDeltaTime() * 100.0f;
		position.y += (input.KeyState(Key::S) - input.KeyState(Key::W)) * time.GetDeltaTime() * 100.0f;
		size.x -= (input.KeyState(Key::Left)) / 100.0f;
		size.x += (input.KeyState(Key::Right)) / 100.0f;
		size.y -= (input.KeyState(Key::Up)) / 100.0f;
		size.y += (input.KeyState(Key::Down)) / 100.0f;
		rotation += (input.KeyState(Key::R)) / 10.0f;
		rotation -= (input.KeyState(Key::F)) / 10.0f;

		renderer.Background();

		renderer.Sprite(&sprite, position, size, rotation);


		Console::PrintMsg("X: %f Y: %f R: %f", position.x, position.y, rotation);


		window.Update();
		//glBindVertexArray(0);
		//glUseProgram(0);
		//glActiveTexture(0);
		//glBindTexture(GL_TEXTURE_2D, 0);
	}
	Core::Unitialize();
}