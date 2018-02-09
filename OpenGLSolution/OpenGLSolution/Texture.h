#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>
class Texture
{
private:
	GLuint texture;
	int width, height;
public:
	Texture();
	~Texture();
};

