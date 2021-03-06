#include "en_mesh.h"
#include <GL/glew.h>

namespace Engine
{
	Mesh::Mesh(Primitive& primitive, glm::vec3 position, glm::vec3 origin, glm::vec3 rotation, glm::vec3 scale)
		: Mesh(primitive.verticies, primitive.indicies, position, origin, rotation, scale)
	{
	}
	Mesh::Mesh(
		Verticies* verticies, 
		Indices* indicies, 
		glm::vec3 position, 
		glm::vec3 origin, 
		glm::vec3 rotation, 
		glm::vec3 scale
	)
	{
		this->verticies = verticies;
		this->indicies = indicies;
		this->position = position;
		this->origin = origin;
		this->rotation = rotation;
		this->scale = scale;

		Initialize();
		UpdateMatrix();
	}
	void Mesh::Initialize()
	{
		// Create VAO
		glCreateVertexArrays(1, &VAO);
		glBindVertexArray(this->VAO);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, verticies->size, verticies->values, GL_STATIC_DRAW);

		if (indicies->length > 0)
		{
			glGenBuffers(1, &EBO);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies->size, indicies->values, GL_DYNAMIC_DRAW);
		}

		// Position
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
		glEnableVertexAttribArray(0);
		// Color
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));
		glEnableVertexAttribArray(1);
		// Texcoord
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texCoord));
		glEnableVertexAttribArray(2);
		// normals
		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
		glEnableVertexAttribArray(3);

		glBindVertexArray(0);

		glBindTexture(GL_TEXTURE_2D, 0);
	}
	void Mesh::UpdateMatrix()
	{
		using namespace glm;

		matrix = glm::mat4(1.f);
		//matrix = translate(matrix, origin);
		//matrix = rotate(matrix, radians(rotation.x), vec3(1.f, 0.f, 0.f));
		//matrix = rotate(matrix, radians(rotation.y), vec3(0.f, 1.f, 0.f));

		matrix = glm::scale(matrix, scale);
		matrix = translate(matrix, position);
		matrix = rotate(matrix, radians(rotation.z), vec3(0.f, 0.f, 1.f));
	}
	glm::mat4& Mesh::GetMatrix()
	{
		return matrix;
	}
	glm::vec3& Mesh::GetPosition()
	{
		return position;
	}
	glm::vec3& Mesh::GetOrigin()
	{
		return origin;
	}
	glm::vec3& Mesh::GetRotation()
	{
		return rotation;
	}
	glm::vec3& Mesh::GetScale()
	{
		return scale;
	}
}
