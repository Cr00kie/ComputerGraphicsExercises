#ifndef _H_Cone_H_
#define _H_Cone_H_

#include "ColorMaterialEntity.h"
class Cone :
    public ColorMaterialEntity
{
public:
    Cone(GLdouble h, GLdouble r, GLdouble R, GLuint nRings, GLuint nSamples, glm::vec4 col = {0,0,0,1});
};

#endif