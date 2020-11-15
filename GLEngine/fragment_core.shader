#version 440 

in vec2 vs_texcoord;
out vec4 fs_color;

uniform sampler2D Texture;  

void main()
{
	vec4 texColor = texture(Texture, vs_texcoord);

	if (texColor.a < 0.1)
		discard;

	fs_color = texColor;
}