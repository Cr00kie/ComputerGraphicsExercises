#ifndef _H_Star3D_H_
#define _H_Star3d_H_

#include "EntityWithTexture.h"
class Star3D :
    public EntityWithTexture
{
public:
    Star3D(GLdouble re, GLuint np, GLdouble h, const std::string& imgPath);

    void render(const glm::mat4& modelViewMat) const override;
    void update() override;

private:

    float rotationZ = 4;
    float rotationY = 2;
    float rotSpeedZ = 1;
    float rotSpeedY = 1;
};

#endif