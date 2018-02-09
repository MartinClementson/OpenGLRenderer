#include "Mesh.h"


using namespace GEO;
Mesh::Mesh()
{
}


Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

TransformNode * GEO::Mesh::GetTransform() const
{
	return nullptr;
}
