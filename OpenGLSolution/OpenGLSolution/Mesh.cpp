#include "Mesh.h"


using namespace GEO;
Mesh::Mesh()
{

}


Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void GEO::Mesh::Draw()
{
	if (this->transform.GetDirtyState())
		this->transform.Update();
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, this->vertices.size());
	glBindVertexArray(0);
}

TransformNode* GEO::Mesh::GetTransform() 
{
	return &this->transform;
}
