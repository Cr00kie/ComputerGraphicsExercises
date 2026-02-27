#pragma once
#include "SingleColorEntity.h"
class Star3D :
    public SingleColorEntity
{
public:
    Star3D(GLdouble re, GLuint np, GLdouble h, glm::vec4 color);

    void render(const glm::mat4& modelViewMat) const override;
    void update() override;

private:

    float rotationZ = 4;
    float rotationY = 2;
};

