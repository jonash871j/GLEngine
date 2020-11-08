#version 440 

in vec3 vs_position;
in vec3 vs_color;
in vec2 vs_texcoord;

out vec4 fs_color;

uniform sampler2D Texture;  

void main()
{
	//fs_color = vec4(vs_color, 1.0f);
	fs_color = texture(Texture, vs_texcoord)/* * vec4(vs_color, 1.0f)*/;
}