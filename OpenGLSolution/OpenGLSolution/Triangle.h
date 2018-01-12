#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>

class Triangle
{
public:
	Triangle();
	~Triangle();

	void Draw();

private:
	GLfloat vertices[9] =
	{
		-0.5f,-0.5f, 0.0f, // Bottom left
		0.5f, -0.5f, 0.0f, // Bottom right
		0.0f,  0.5,  0.0f  // Top
	};
	GLuint VBO, VAO;


};

