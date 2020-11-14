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

	void Renderer::Update()
	{
		DGLFW_CALL(glfwSwapBuffers(window->glfwWindow));
		glfwSwapInterval(0); // FPS Limiter, 0 = none
		DGL_CALL(glFlush());
	}

	void Renderer::Clear()
	{
		DGL_CALL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT));
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

	void Renderer::Line(float x1, float y1, float x2, float y2)
	{
		glBegin(GL_LINES);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
		glEnd();
	}
	void Renderer::Mesh(Engine::Mesh* mesh, Texture* texture)
	{
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
		
		if (mesh->indicies->length  == 0)
			glDrawArrays(GL_TRIANGLES, 0, mesh->verticies->length);
		else
			glDrawElements(GL_TRIANGLES, mesh->indicies->length, GL_UNSIGNED_INT, 0);
	}
	void Renderer::Sprite(Engine::Sprite* sprite, const Vector2D& position, float rotation, const Vector2D& size)
	{
		const Vector2D spriteSize = { sprite->width * size.x, sprite->height * size.y };

		sprite->mesh->position = 
		{ 
			(2.0f * (position.x + spriteSize.x / 2.0f) / w - 1.0f) * (w / spriteSize.x),
			-(2.0f * (position.y + spriteSize.y / 2.0f) / h - 1.0f) * (h / spriteSize.y),
			0.0f
		};
		sprite->mesh->scale = { spriteSize.x / w, spriteSize.y / h, 0.0f };
		sprite->mesh->rotation = { 0, 0, rotation }; // Not working correctly

		Mesh(sprite->mesh, sprite->texture);
	}
	void Renderer::SetShaderProgram(ShaderProgram* shaderProgram)
	{
		this->shaderProgram = shaderProgram;
	}
}