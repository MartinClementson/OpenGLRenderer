#version 330 core //Core shader language for 3.3
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 inColor;
layout (location = 2) in vec2 inTexCoord;

out vec3 color;
out vec2 texCoord;

void main()
{
	gl_Position  = vec4( position,1.0);
	color		 = inColor;
	texCoord     = vec2(inTexCoord.x,1.0 - inTexCoord.y);

};