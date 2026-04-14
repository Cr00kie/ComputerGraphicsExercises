#ifndef _H_Disk_H_
#define _H_Disk_H_

#include "ColorMaterialEntity.h"
class Disk :
    public ColorMaterialEntity
{
public:
    Disk(GLdouble R, GLdouble r, GLuint nRings, GLuint nSamples, glm::vec4 col = {0,0,0,1});
};

#endif