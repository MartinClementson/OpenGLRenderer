#version 330 core //Core shader language for 3.3

layout (location = 0) in vec3 position;



out vec3 color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj; 

void main()
{
	gl_Position  =  proj * view * model*  vec4( position,1.0);

};