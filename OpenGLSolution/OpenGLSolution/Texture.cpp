#include "Texture.h"
#include "SOIL2\SOIL2.h"


void Texture::SetActive(GLint uniformLoc)
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glUniform1i(uniformLoc, 0);

}

bool Texture::LoadImage(const char * filepath)
{
	glBindTexture(GL_TEXTURE_2D, texture);

	unsigned char *image = SOIL_load_image(filepath, &width, &height, 0, SOIL_LOAD_RGBA);
	if (image == nullptr)
		return false;

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);

	glBindTexture(GL_TEXTURE_2D, 0);
	return true;
}

Texture::Texture()
{
	//Create and bind	
	glGenTextures(1, &this->texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	//Set Parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//Unbind the created texture
	glBindTexture(GL_TEXTURE_2D, 0);

}

Texture::Texture(const char * filepath)
{
	glGenTextures(1, &this->texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	//Set Parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (!LoadImage(filepath))
		throw std::string("Cannot find file");

	//Unbind the created texture
	glBindTexture(GL_TEXTURE_2D,0);
	

}


Texture::~Texture()
{
}
