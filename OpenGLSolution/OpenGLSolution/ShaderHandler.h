#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>

class ShaderHandler
{
public:
	ShaderHandler();
	~ShaderHandler();
	bool Init();
	bool UseShaders();

private:
	GLuint shaderProgram = 0;
	bool CompileShaders();


	const GLchar *vertexShaderSource = "#version 330 core\n" //Core shader language for 3.3
		"layout (location = 0) in vec3 position;\n"
		"void main()\n"
		"{\n"
		"gl_Position = vec4( position.x,position.y,position.z,1.0);\n"

		"}";

	const GLchar *fragmentShaderSource = "#version 330 core\n"
		"out vec4 color;\n"
		"void main()\n"
		"{\n"
		"color = vec4(1.0f,0.5f,0.2f,1.0f);\n"
		"}";
};

