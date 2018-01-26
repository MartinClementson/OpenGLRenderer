#include "Triangle.h"



Triangle::Triangle()
{



	vertices[0] = Vertex(-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f);
	vertices[1] = Vertex(0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f);
	vertices[2] = Vertex(0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f);


	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}


Triangle::~Triangle()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

void Triangle::Draw()
{

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
