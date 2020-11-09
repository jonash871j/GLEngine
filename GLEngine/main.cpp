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
	
	Sprite sprite("Images/Bricks.png", &coreProgram);

	float xPos = 0.0f;
	float yPos = 0.0f;

	float angle = 0.0f;

	while (!window.GetIsClosed())
	{
		renderer.Clear();
		
		if (input.KeyPressed(Key::Escape))
			window.Close();


		if (input.KeyState(Key::D))
			angle += 1.0f;
		if (input.KeyState(Key::A))
			angle -= 1.0f;

		if (angle > 359.0f)
			angle = 0.0f;
		if (angle < 0.0f)
			angle = 359.0f;

		if (input.KeyState(Key::W))
		{
			xPos += Math::Sin(angle * Math::PI / 180) * 0.1f;
			yPos += Math::Cos(angle * Math::PI / 180) * 0.1f;
		}
		Console::PrintMsg("%f", angle);

		/*mesh1.GetPosition() = glm::vec3(xPos, yPos, 0.0f);
		mesh2.GetPosition() -= glm::vec3(0.0001f, 0.0f, 0.0f);
	*/
		renderer.Background();
		renderer.Sprite(&sprite, { xPos, yPos }, 0.0f);
		
		window.Update();

		// Not working
		//glBindVertexArray(0);
		//glUseProgram(0);
		//glActiveTexture(0);
		//glBindTexture(GL_TEXTURE_2D, 0);
	}
	Core::Unitialize();
}