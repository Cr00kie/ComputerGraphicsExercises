#ifndef _H_SphereWithTexture_H_
#define _H_SphereWithTexture_H_

#include "EntityWithTexture.h"
class SphereWithTexture :
    public EntityWithTexture
{
public:
    SphereWithTexture(GLdouble r, GLuint nParallels, GLuint nMeridians, const std::string& imageName, GLfloat alpha = 1.f);
};

#endif