#ifndef _H_Cube_H_
#define _H_Cube_H_

#include "SingleColorEntity.h"
class Cube :
    public SingleColorEntity
{
public:
    Cube(GLdouble length, glm::vec4 col = {0.0,0.0,0.0,1.0});
    void render(const glm::mat4& modelViewMat) const override;
};

#endif

