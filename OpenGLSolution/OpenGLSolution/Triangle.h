#pragma once
#include "Mesh.h"


namespace GEO {

class Triangle : public Mesh
{
public:
	Triangle();
	~Triangle();

	void Draw();
};

} // End namespace GEO

