#include "Texture.h"
#include "SOIL2\SOIL2.h"


Texture::Texture()
{
	glGenTextures(1, &this->texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	//Set Parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//unsigned char *image = SOIL_load_image()
}


Texture::~Texture()
{
}
