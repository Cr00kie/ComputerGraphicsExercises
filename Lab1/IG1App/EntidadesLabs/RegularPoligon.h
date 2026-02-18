#ifndef _H_RegularPoligon_H_
#define _H_RegularPoligon_H_

#include "SingleColorEntity.h"

class RegularPoligon :
    public SingleColorEntity
{
public:
    RegularPoligon(GLuint num, GLdouble rad, glm::vec4 col);
};

#endif
