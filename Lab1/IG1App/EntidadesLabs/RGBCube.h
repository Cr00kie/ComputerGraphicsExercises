#pragma once
#include "../Entity.h"
class RGBCube :
    public EntityWithColors
{
public:
    RGBCube(GLdouble length);
    void render(const glm::mat4& modelViewMat) const override;
};

