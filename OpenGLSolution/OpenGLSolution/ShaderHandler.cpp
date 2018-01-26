#include "ShaderHandler.h"



ShaderHandler::ShaderHandler()
{
	shaderFiles[COLOR][VS_SHADER] = "core.vs";
	shaderFiles[COLOR][FS_SHADER] = "core.frag";
}


ShaderHandler::~ShaderHandler()
{
}

bool ShaderHandler::Init()
{
	bool success = true;

	for (size_t i = 0; i < NUM_SHADERS; i++)
	{
		std::cout << shaderFiles[i][VS_SHADER] << std::endl;
		std::cout << shaderFiles[i][FS_SHADER] << std::endl;
		const char * vs_str = shaderFiles[i][VS_SHADER].c_str();
		const char * fs_str = shaderFiles[i][FS_SHADER].c_str();
		try {

		this->shaders.push_back(Shader(vs_str, fs_str));
		}
		catch (int e) {
			std::cout << "Error creating shader #" << i << std::endl;
			success = false;
		}
	}

	return success;	
}

bool ShaderHandler::UseShaders(Shaders type)
{
	this->shaders[type].Use();
	return true;
}

