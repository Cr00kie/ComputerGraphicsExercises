#pragma once
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
};

