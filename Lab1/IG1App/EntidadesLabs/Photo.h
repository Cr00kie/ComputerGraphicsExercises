#pragma once
#include "EntityWithTexture.h"
class Photo : public EntityWithTexture
{
public:
	Photo(GLdouble length, const std::string& imageName, GLfloat alpha = 255);

	void update() override;
private:
	GLdouble mLength;
};

