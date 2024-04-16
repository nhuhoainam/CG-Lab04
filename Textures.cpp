#include <SOIL.h>
#include <string>
#ifdef _WIN32
	#include <direct.h>
	#define getcwd _getcwd // stupid MSFT "deprecation" warning
#elif
	#include <unistd.h>
#endif
#include <iostream>

#include "Shape.h"

std::string get_working_path()
{
	char temp[300];
	return (getcwd(temp, sizeof(temp)) ? std::string(temp) : std::string(""));
}

void loadTexture(GLuint* texture, const char* path) {
	*texture = SOIL_load_OGL_texture(path,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_MULTIPLY_ALPHA
	);
	if (*texture == NULL) {
		printf("[Texture loader] \"%s\" failed to load!\n", path);
	}
}

bool LoadGLTextures() {
	std::cout << get_working_path() << std::endl;
	loadTexture(&texture[0], "asset/wall.jpeg");
	if (texture[0] == 0) {
		return false;
	}
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return true;
}