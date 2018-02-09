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

TransformNode* GEO::Mesh::GetTransform() 
{
	return &this->transform;
}
