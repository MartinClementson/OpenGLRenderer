#version 330 core

in vec3 color;
in vec2 texCoord;

out vec4 outColor;

uniform sampler2D Diffuse;

void main()
{
	//color = vec4(color,1.0f);
	outColor = texture(Diffuse,texCoord);
};