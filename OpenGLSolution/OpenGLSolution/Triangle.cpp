#include "Triangle.h"


using namespace GEO;
Triangle::Triangle()
{

	this->vertices.reserve(3);
	this->vertices.push_back(Vertex(-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.25f, 0.25f));
	this->vertices.push_back(Vertex(0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.75f, 0.25f));
	this->vertices.push_back(Vertex(0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.5f, 0.75f));
	Vertex localVertices[3];
	localVertices[0] = Vertex(-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.25f, 0.25f);
	localVertices[1] = Vertex(0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.75f, 0.25f);
	localVertices[2] = Vertex(0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.5f, 0.75f);
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)* vertices.size(), vertices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices.data(), GL_STATIC_DRAW);

	//Position Attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	//Color Attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	//UV attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}


Triangle::~Triangle()
{
	
}

void Triangle::Draw()
{

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
