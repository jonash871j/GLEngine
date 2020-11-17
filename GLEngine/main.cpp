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

	enum Types
	{
		Stone,
		Sccissors,
		Paper,
		Undefined,
	};

	Sprite sprType[3]
	{ 
		(new Texture("Images/Scissors.png")), 
		(new Texture("Images/Rock.png")),
		(new Texture("Images/Paper.png"))
	};

	Sprite sprWin(new Texture("Images/win.png"));
	Sprite sprLost(new Texture("Images/lost.png"));

	int a = Undefined;
	int b = Undefined;

	while (!window.GetIsClosed())
	{
		if (input.KeyPressed(Key::Escape))
			window.Close();
			
		if (input.KeyPressed(Key::Space))
		{
			a = rand() % 2;
			b = rand() % 2;
		}	
		
		if (a != Undefined)
		{
			renderer.SpriteEx(&sprType[b], { 0, 0 }, 325.0f);
			renderer.SpriteEx(&sprType[a], { 96, 0 }, 45.0f);

			if ((a == Stone) && (b == Sccissors))
				renderer.Sprite(&sprWin);
			else if ((a == Sccissors) && (b == Paper))
				renderer.Sprite(&sprWin);
			else if ((a == Paper) && (b == Stone))
				renderer.Sprite(&sprWin);
			else if (a != b)
				renderer.Sprite(&sprLost);
		}

		window.Update();
	}
	Core::Unitialize();
}