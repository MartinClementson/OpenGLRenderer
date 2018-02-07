#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "TransformNode.h"
#include <vector>
namespace GEO {
struct Float3
{
	GLfloat x, y, z;
	Float3() {};
	Float3(GLfloat x, GLfloat y, GLfloat z) { this->x = x; this->y = y; this->z = z; };
};
struct Float2
{
	GLfloat x, y;
	Float2() {};
	Float2(GLfloat x, GLfloat y) { this->x = x; this->y = y;};
};
struct Vertex
{
	Float3 position;
	Float3 color;
	Float2 uv;
	Vertex() {};
	Vertex(Float3 pos, Float3 color,Float2 uv)
	{
		this->position.x = pos.x;
		this->position.y = pos.y;
		this->position.z = pos.z;
		this->color.x    = color.x;
		this->color.y    = color.y;
		this->color.z    = color.z;
		this->uv.x		 = uv.x;
		this->uv.y		 = uv.y;
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

