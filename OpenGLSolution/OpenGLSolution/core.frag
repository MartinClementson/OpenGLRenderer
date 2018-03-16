#version 330 core

in vec3 color;
in vec2 texCoord;

uniform vec3 lightPosition;
uniform vec3 lightColor;


out vec4 outColor;

uniform sampler2D Diffuse;

void main()
{
	//color = vec4(color,1.0f);
	vec3 temp = lightPosition;
	temp -= lightPosition;
	outColor = vec4(lightColor + temp,1.0f); //texture(Diffuse,texCoord);
};