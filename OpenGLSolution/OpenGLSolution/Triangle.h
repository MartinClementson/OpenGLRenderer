#pragma once
#include "Mesh.h"


namespace GEO {

class Triangle : public Mesh
{
public:
	Triangle();
	~Triangle();

	void Draw() { Mesh::Draw(); };
};

} // End namespace GEO

