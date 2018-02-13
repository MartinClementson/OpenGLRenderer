#pragma once
#include "Mesh.h"

namespace GEO{

class Cube :
	public Mesh
{
public:
	Cube();
	virtual ~Cube();

	void Draw();
};
}

