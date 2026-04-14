#ifndef _H_TORUS_H_
#define _H_TORUS_H_

#include "ColorMaterialEntity.h"
class Torus :
    public ColorMaterialEntity
{
public:
    Torus(GLdouble R, GLdouble r, GLuint nPoints = 40, GLuint nSamples = 40, glm::vec4 col = {0,0,0,1});
};

#endif