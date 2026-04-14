#ifndef _H_IndexedBox_H_
#define _H_IndexedBox_H_

#include "ColorMaterialEntity.h"
class IndexedBox :
    public ColorMaterialEntity
{
public:
    IndexedBox(GLdouble l, glm::vec4 col = { 0,0,0,1 });
};

#endif