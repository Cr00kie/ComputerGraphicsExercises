#pragma once
#include "SingleColorEntity.h"

class RegularPoligon :
    public SingleColorEntity
{
public:
    RegularPoligon(GLuint num, GLdouble rad, glm::vec4 col);
};

