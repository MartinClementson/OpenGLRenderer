#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include "Shader.h"
#include <vector>
#include <string>

enum ShaderFiles {
	VS_SHADER = 0,
	FS_SHADER = 1
};

enum Shaders {
	COLOR = 0,

	
	NUM_SHADERS
};


class ShaderHandler
{
public:
	ShaderHandler();
	~ShaderHandler();
	bool Init();
	bool UseShaders(Shaders type = Shaders::COLOR);

private:
	std::vector<Shader> shaders;
	std::string shaderFiles[NUM_SHADERS][2];
	
};

