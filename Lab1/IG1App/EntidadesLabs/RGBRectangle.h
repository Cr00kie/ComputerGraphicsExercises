#ifndef _H_RGBRectangle_H_
#define _H_RGBRectangle_H_

#include "../Entity.h"

class RGBRectangle :
    public EntityWithColors
{
public:
    RGBRectangle(GLdouble w, GLdouble h);
    void render(const glm::mat4& modelViewMat) const override;
};

#endif
