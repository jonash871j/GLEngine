#include <iostream>
#include "engine.h"
#include <GL/glew.h>
#include <glm.hpp>
#include <vec2.hpp>
#include <vec3.hpp>
#include <vec4.hpp>
#include <mat4x4.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

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
	
	Square square;
	Mesh mesh1(square.verticies, square.indices);
	Mesh mesh2(square.verticies, square.indices);

	// VAO, VBO, EBO ***********************************
	//uint32_t VAO;
	//glCreateVertexArrays(1, &VAO);
	//glBindVertexArray(VAO);

	//uint32_t VBO;
	//glGenBuffers(1, &VBO);
	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBufferData(GL_ARRAY_BUFFER, square.verticies->size, square.verticies->values, GL_STATIC_DRAW);

	//uint32_t EBO;
	//glGenBuffers(1, &EBO);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, square.indices->size, square.indices->values, GL_STATIC_DRAW);

	//// Position
	//glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(Vertex), (void*)offsetof(Vertex, position));
	//glEnableVertexAttribArray(0);

	//// Color
	//glVertexAttribPointer(1, 3, GL_FLOAT, false, sizeof(Vertex), (void*)offsetof(Vertex, color));
	//glEnableVertexAttribArray(1);

	//// Texture coordinates
	//glVertexAttribPointer(2, 3, GL_FLOAT, false, sizeof(Vertex), (void*)offsetof(Vertex, texCoord));
	//glEnableVertexAttribArray(2);

	//glBindVertexArray(0);
	//glBindTexture(GL_TEXTURE_2D, 0);

	//// Load textures
	//Image image("Images/Bricks.png");

	//uint32_t texture0;
	//GL_CALL(glGenTextures(1, &texture0));
	//GL_CALL(glBindTexture(GL_TEXTURE_2D, texture0));

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	//GL_CALL(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.GetWidth(), image.GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.GetPixels()));
	//GL_CALL(glGenerateMipmap(GL_TEXTURE_2D));


	glm::mat4 ModelMatrix(1.0f);
	//	ModelMatrix = glm::translate(ModelMatrix, glm::vec3(v.y, 0.0f, 0.0f));
	//ModelMatrix = glm::rotate(ModelMatrix, glm::radians(10.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	//ModelMatrix = glm::rotate(ModelMatrix, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	//ModelMatrix = glm::rotate(ModelMatrix, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	//ModelMatrix = glm::scale(ModelMatrix, glm::vec3(1.0f));

	float xPos = 0.0f;
	float yPos = 0.0f;

	while (!window.GetIsClosed())
	{
		renderer.Clear();
		
		if (input.KeyPressed(Key::Escape))
			window.Close();

		if (input.KeyState(Key::Up))
			yPos += 0.01f;

		if (input.KeyState(Key::Down))
			yPos -= 0.01f;

		if (input.KeyState(Key::Left))
			xPos -= 0.01f;

		if (input.KeyState(Key::Right))
			xPos += 0.01f;

		if (input.MouseState(MouseButton::Left))
			renderer.Color(32, 255, 64);
		else
			renderer.Color(0, 0, 64);

		mesh1.GetPosition() = glm::vec3(xPos, yPos, 0.0f);
		mesh2.GetPosition() -= glm::vec3(0.001f, 0.0f, 0.0f);

		renderer.Background();
		renderer.Mesh(&mesh1, &coreProgram);
		renderer.Mesh(&mesh2, &coreProgram);
		//glBindVertexArray(VAO); 	// Bind vertex array object
		////glDrawArrays(GL_TRIANGLES, 0, square.verticies->length);
		//glDrawElements(GL_TRIANGLES, square.indices->length, GL_UNSIGNED_INT, nullptr);

		//glUniform1i(glGetUniformLocation(coreProgram.GetId(), "texture0"), 0);
		//glUniformMatrix4fv(glGetUniformLocation(coreProgram.GetId(), "ModelMatrix"), 1, false, glm::value_ptr(ModelMatrix));

		//ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.001f, 0.0f, 0.0f));
		////ModelMatrix = glm::rotate(ModelMatrix, glm::radians(1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		//
		//// Activate texture
		//glActiveTexture(GL_TEXTURE);
		//glBindTexture(GL_TEXTURE_2D, texture0);

		//glUseProgram(coreProgram.GetId());

		window.Update();

		// Not working
		//glBindVertexArray(0);
		//glUseProgram(0);
		//glActiveTexture(0);
		//glBindTexture(GL_TEXTURE_2D, 0);
	}
	Core::Unitialize();
}