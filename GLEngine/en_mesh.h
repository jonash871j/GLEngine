#pragma once
#include "en_def.h"
#include "en_verticies.h"
#include "en_indices.h"
#include "en_primitive.h"

#include <glm.hpp>
#include <vec2.hpp>
#include <vec3.hpp>
#include <vec4.hpp>
#include <mat4x4.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

namespace Engine
{
	class Mesh
	{
		friend class Renderer;
	private:
		Verticies* verticies = nullptr;
		Indices* indicies = nullptr;

	private:
		uint32_t VBO; // Vertex Buffer Objects
		uint32_t VAO; // Vertex Arrary Object
		uint32_t EBO; // Element Buffer Object

	private:
		glm::mat4 matrix;
		glm::vec3 position;
		glm::vec3 origin;
		glm::vec3 rotation;
		glm::vec3 scale;

	public:
		Mesh(Primitive& primitive,
			 glm::vec3 position = glm::vec3(0.f),
			 glm::vec3 origin = glm::vec3(0.f),
			 glm::vec3 rotation = glm::vec3(0.f),
			 glm::vec3 scale = glm::vec3(1.f)
		);
		Mesh(
			Verticies* verticies, 
			Indices* indicies, 
			glm::vec3 position = glm::vec3(0.f),
			glm::vec3 origin = glm::vec3(0.f),
			glm::vec3 rotation = glm::vec3(0.f),
			glm::vec3 scale = glm::vec3(1.f)
		);

	private:
		void Initialize();
		void UpdateMatrix();

	public:
		glm::mat4& GetMatrix();
		glm::vec3& GetPosition();
		glm::vec3& GetOrigin();
		glm::vec3& GetRotation();
		glm::vec3& GetScale();
	};
}

