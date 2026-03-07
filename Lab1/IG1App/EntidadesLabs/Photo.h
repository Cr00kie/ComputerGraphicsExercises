#ifndef _H_Photo_H_
#define _H_Photo_H_

#include "EntityWithTexture.h"
class Photo : public EntityWithTexture
{
public:
	Photo(GLdouble length, GLfloat alpha = 255);

	void update() override;
private:
	GLdouble mLength;
};

#endif