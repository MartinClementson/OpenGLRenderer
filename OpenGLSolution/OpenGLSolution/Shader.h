#pragma once

#include <GL\glew.h>
class Shader
{
public:
	GLuint Program;

	Shader(const GLchar *vertexPath, const GLchar *fragmentPath);
	~Shader();

	void Use();
};

