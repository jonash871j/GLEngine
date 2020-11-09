#include "en_renderer.h"
#include "en_window.h"

#include <GL/glew.h>
#include <glfw3.h>

namespace Engine
{
	Renderer::Renderer()
	{
	}
	void Renderer::UpdateProperties(Window* window)
	{
		this->window = window;
		w = (float)window->width;
		h = (float)window->height;
	}

	void Renderer::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
	{
		c = { r, g, b, a };
		//glColor4b(r, g, b, a);
	}

	void Renderer::Background()
	{
		glClearColor(0.003f * (float)c.r, 0.003f * (float)c.g, 0.003f * (float)c.b, 0.003f * (float)c.a);
	}

	void Renderer::Line(int32_t x1, int32_t y1, int32_t x2, int32_t y2)
	{
		float x1f = 2.0f * (float)x1 / w - 1.0f;
		float y1f = 2.0f * (float)y1 / h - 1.0f;
		float x2f = 2.0f * (float)x2 / w - 1.0f;
		float y2f = 2.0f * (float)y2 / h - 1.0f;
		Line(x1f, y1f, x2f, y2f);
	}

	void Renderer::Line(float x1, float y1, float x2, float y2)
	{
		glBegin(GL_LINES);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
		glEnd();
	}
	void Renderer::Mesh(Engine::Mesh* mesh, ShaderProgram* shaderProgram, Texture* texture)
	{
		mesh->position.x = 2.0f * (mesh->position.x / w) - 0.5f;
		mesh->position.y = 2.0f * (mesh->position.y / h) + 0.5f;
		mesh->UpdateMatrix();

		DGL_CALL(glBindVertexArray(mesh->VAO));

		if (shaderProgram)
		{
			if (texture)
			{
				glUniform1i(glGetUniformLocation(shaderProgram->GetId(), "Texture"), 0);
				glActiveTexture(GL_TEXTURE);
				glBindTexture(GL_TEXTURE_2D, texture->id);
			}

			DGL_CALL(glUseProgram(shaderProgram->GetId()));
			DGL_CALL(glUniformMatrix4fv(glGetUniformLocation(shaderProgram->GetId(), "Matrix"), 1, false, glm::value_ptr(mesh->matrix)));
		}
		

		if (mesh->indicies->length == 0)
			glDrawArrays(GL_TRIANGLES, 0, mesh->verticies->length);
		else
			glDrawElements(GL_TRIANGLES, mesh->indicies->length, GL_UNSIGNED_INT, 0);
	}
	void Renderer::Sprite(Engine::Sprite* sprite, Vector2D position, float angle)
	{
		sprite->mesh->position = { position.x, position.y, 0.0f };
		sprite->mesh->rotation.z = angle;
		Mesh(sprite->mesh, sprite->shaderProgram, sprite->texture);
	}
	void Renderer::Update()
	{
		DGLFW_CALL(glfwSwapBuffers(window->glfwWindow));
		DGL_CALL(glFlush());
	}
	void Renderer::Clear()
	{
		DGL_CALL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT));
	}
}