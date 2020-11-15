#include <iostream>
#include "engine.h"
#include <GL/glew.h>

using namespace Engine;

int main()
{
	// https://www.youtube.com/watch?v=oNNFazrxy6Q
	Core::Initialize();

	Window window(256, 128, "Program");
	Renderer& renderer = window.GetRenderer();
	Input& input = window.GetInput();
	Time& time = window.GetTime();
	window.SetScaling(4, 4);

	//ShaderProgram shaderTest;
	//Shader fragmentShader("fragment_core.shader", Shader::Type::Fragment, shaderTest);
	//Shader vertexShader("vertex_core.shader", Shader::Type::Vertex, shaderTest);
	//shaderTest.Link();
	//renderer.SetShaderProgram(&shaderTest);
	renderer.SetShaderProgram(&ShaderProgram::CreateSpriteProgram());

	Texture texture("Images/gold_brick.png", Texture::Mode::Nearest);

	Sprite sprite(&texture, 16, 8, 0);

	Vector2D position;
	Vector2D size = { 1.0f, 1.0f };
	float rotation = 0.0f;

	while (!window.GetIsClosed())
	{
		if (input.KeyPressed(Key::Escape))
			window.Close();

		if (input.KeyPressed(Key::F1))
			window.SetScaling(4, 4);
		if (input.KeyPressed(Key::F2))
			window.SetScaling(1, 1);


		//position.x += (input.KeyState(Key::D) - input.KeyState(Key::A)) * time.GetDeltaTime() * 100.0f;
		//position.y += (input.KeyState(Key::S) - input.KeyState(Key::W)) * time.GetDeltaTime() * 100.0f;
		position = input.MousePosition();
		size.x -= ((float)input.KeyState(Key::Left)) / 100.0f;
		size.x += ((float)input.KeyState(Key::Right)) / 100.0f;
		size.y -= ((float)input.KeyState(Key::Up)) / 100.0f;
		size.y += ((float)input.KeyState(Key::Down)) / 100.0f;
		rotation += ((float)input.KeyState(Key::R)) / 10.0f;
		rotation -= ((float)input.KeyState(Key::F)) / 10.0f;

		renderer.SpriteEx(&sprite, position, rotation, size);
		renderer.Sprite(&sprite, { 0.0f, 0.0f }, { 1, 0});
		renderer.Sprite(&sprite, { 0.0f, 64.0f });
		


		//Console::PrintMsg("X: %f Y: %f R: %f", position.x, position.y, rotation);


		window.Update();
	}
	Core::Unitialize();
}