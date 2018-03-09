#pragma once
#include "Mesh.h"

namespace GEO{

class Cube :
	public Mesh
{
public:
	Cube();
	virtual ~Cube();

	void Draw() { Mesh::Draw(); };

//
//private:
//	float vertices[] = {
//		//Vertices according to faces
//		-1.0f, -1.0f, 1.0f, //Vertex 0
//		1.0f, -1.0f, 1.0f,  //v1
//		-1.0f, 1.0f, 1.0f,  //v2
//		1.0f, 1.0f, 1.0f,   //v3
//
//		1.0f, -1.0f, 1.0f,  //...
//		1.0f, -1.0f, -1.0f,
//		1.0f, 1.0f, 1.0f,
//		1.0f, 1.0f, -1.0f,
//
//		1.0f, -1.0f, -1.0f,
//		-1.0f, -1.0f, -1.0f,
//		1.0f, 1.0f, -1.0f,
//		-1.0f, 1.0f, -1.0f,
//
//		-1.0f, -1.0f, -1.0f,
//		-1.0f, -1.0f, 1.0f,
//		-1.0f, 1.0f, -1.0f,
//		-1.0f, 1.0f, 1.0f,
//
//		-1.0f, -1.0f, -1.0f,
//		1.0f, -1.0f, -1.0f,
//		-1.0f, -1.0f, 1.0f,
//		1.0f, -1.0f, 1.0f,
//
//		-1.0f, 1.0f, 1.0f,
//		1.0f, 1.0f, 1.0f,
//		-1.0f, 1.0f, -1.0f,
//		1.0f, 1.0f, -1.0f,
//	};
};
}

