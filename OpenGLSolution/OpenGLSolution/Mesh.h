#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "TransformNode.h"
#include <vector>
namespace GEO {

struct Vertex
{
	GLfloat x, y, z;
	GLfloat r, g, b;
	GLfloat u, v;
	Vertex() {};
	Vertex(GLfloat x, GLfloat y, GLfloat z, GLfloat r, GLfloat g, GLfloat b, GLfloat u, GLfloat v)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->r = r;
		this->g = g;
		this->b = b;
		this->u = u;
		this->v = v;
	}
};
class Mesh
{
public:
	Mesh();
	virtual ~Mesh();

	virtual void Draw() = 0;

	TransformNode* GetTransform()const;
protected:
	TransformNode transform;
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	GLuint VBO, VAO,EBO;
};


}// End namespace GEO

