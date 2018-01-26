#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>

struct Vertex
{
	GLfloat x, y, z;
	GLfloat r, g, b;
	Vertex() {};
	Vertex(GLfloat x, GLfloat y, GLfloat z, GLfloat r, GLfloat g, GLfloat b)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->r = r;
		this->g = g;
		this->b = b;
	}
};

class Triangle
{
public:
	Triangle();
	~Triangle();

	void Draw();

private:

	Vertex vertices[3];
	
	
	GLuint VBO, VAO;


};

