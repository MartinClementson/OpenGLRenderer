#version 330 core //Core shader language for 3.3
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

out vec3 ourColor;

void main()
{
	gl_Position = vec4( position,1.0);
	ourColor	= color;

};