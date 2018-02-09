#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <string>
class Texture
{
private:
	GLuint texture;
	int width, height;
	unsigned char* image;
public:
	void SetActive(GLint uniformLoc);
	bool LoadImage(const char* filepath);
	Texture();
	Texture(const char* filepath);
	~Texture();
};

