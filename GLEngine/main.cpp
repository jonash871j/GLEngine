#include <iostream>
#include "engine.h"
#include <GL/glew.h>
#include <glm.hpp>
#include <vec2.hpp>
#include <vec3.hpp>
#include <vec4.hpp>
#include <mat4x4.hpp>
#include <gtc/matrix_transform.hpp>


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
	
	// Options *****************************************
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	glBlendFunc(GL_SRC0_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	
	Primitive square = Primitive::CreateSquare();
	Mesh mesh1(square);
	Mesh mesh2(square);

	Texture texture1("Images/Alien.png");
	Texture texture2("Images/Bricks.png");

	float xPos = 0.0f;
	float yPos = 0.0f;

	while (!window.GetIsClosed())
	{
		renderer.Clear();
		
		if (input.KeyPressed(Key::Escape))
			window.Close();

		yPos += float(input.KeyState(Key::Up) - input.KeyState(Key::Down)) / 32.0f;
		xPos += float(input.KeyState(Key::Right) - input.KeyState(Key::Left)) / 32.0f;

		if (input.MouseState(MouseButton::Left))
			renderer.Color(32, 255, 64);
		else
			renderer.Color(0, 0, 64);

		mesh1.GetPosition() = glm::vec3(xPos, yPos, 0.0f);
		mesh2.GetPosition() -= glm::vec3(0.001f, 0.0f, 0.0f);
	
		renderer.Background();
		renderer.Mesh(&mesh1, &coreProgram, &texture1);
		renderer.Mesh(&mesh2, &coreProgram, &texture2);

		window.Update();

		// Not working
		//glBindVertexArray(0);
		//glUseProgram(0);
		//glActiveTexture(0);
		//glBindTexture(GL_TEXTURE_2D, 0);
	}
	Core::Unitialize();
}