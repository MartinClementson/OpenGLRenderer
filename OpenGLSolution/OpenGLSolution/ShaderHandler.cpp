#include "ShaderHandler.h"



ShaderHandler::ShaderHandler()
{
	for (size_t i = 0; i < NUM_SHADERS; i++)
	{
		shaderFiles[i][VS_SHADER] = "";
		shaderFiles[i][FS_SHADER] = "";

	}
	shaderFiles[COLOR][VS_SHADER] = "core.vs";
	shaderFiles[COLOR][FS_SHADER] = "core.frag";

	//shaderFiles[LIGHTING][VS_SHADER] = "lighting.vs";
	//shaderFiles[LIGHTING][FS_SHADER] = "lighting.frag";
	//
	//shaderFiles[LAMP][VS_SHADER] = "lamp.vs";
	//shaderFiles[LAMP][FS_SHADER] = "lamp.frag";
}


ShaderHandler::~ShaderHandler()
{
}

const Shader * ShaderHandler::GetActiveShader() const
{
	if (m_activeShader == NONE)
		return nullptr;
	return &this->shaders[m_activeShader];
}

bool ShaderHandler::Init()
{
	bool success = true;

	for (size_t i = 0; i < NUM_SHADERS; i++)
	{

		if (shaderFiles[i][VS_SHADER] == "" || shaderFiles[i][FS_SHADER] == "")
			continue;

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

bool ShaderHandler::UseShader(Shaders type)
{
	m_activeShader = type;
	this->shaders[type].Use();
	return true;
}

