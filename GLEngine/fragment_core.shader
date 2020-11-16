#version 440 

in vec3 vs_position;
in vec3 vs_color;
in vec2 vs_texcoord;
in vec3 vs_normal;

out vec4 fs_color;


uniform sampler2D Texture;  
uniform vec3 Light;

void main()
{
	// Alpha
	vec4 texColor = texture(Texture, vs_texcoord);

	if (texColor.a < 0.1)
		discard;

	// Ambient light
	vec3 ambientLight = vec3(0.1f, 0.1f, 0.1f);

	// Diffuse light
	vec3 posToLightDirVec = normalize(vs_position - Light);
	vec3 diffuseColor = vec3(1.0f, 1.0f, 1.0f);
	float diffuse = clamp(dot(posToLightDirVec, vs_normal), 0, 1);
	vec3 diffuseFinal = diffuseColor * diffuse;

	fs_color = texture(Texture, vs_texcoord) * vec4(vs_color, 1.0f)	* vec4(ambientLight, 1.0f) + vec4(diffuseFinal, 1.0f);
}