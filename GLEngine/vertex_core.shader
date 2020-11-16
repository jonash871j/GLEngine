#version 440

layout(location = 0) in vec3 vertex_position;
layout(location = 1) in vec3 vertex_color;
layout(location = 2) in vec2 vertex_texcoord;
layout(location = 3) in vec3 vertex_normal;

out vec3 vs_position;
out vec3 vs_color;
out vec2 vs_texcoord;
out vec3 vs_normal;

uniform mat4 Matrix;

void main()
{
	//vs_position = vec4(Matrix * vec4(vertex_position, 1.0f)).xyz;
	//vs_color = vertex_color;
	vs_texcoord = vec2(vertex_texcoord.x, vertex_texcoord.y * -1.0f);
	gl_Position = Matrix * vec4(vertex_position, 1.0f);

	vs_normal = mat3(Matrix) * vertex_normal;

	/*vs_position = vertex_position;
	vs_color = vertex_color;
	vs_texcoord = vec2(vertex_texcoord.x, vertex_texcoord.y * -1.0f);

	gl_Position = vec4(vertex_position, 1.0f);*/

}