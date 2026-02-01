#pragma once
#include "../Entity.h"

class RGBTriangle :
    public EntityWithColors
{
private:
    float m_fOrbitAngle = 0;
    float m_fOrbitRad = glm::sqrt(10000 * 2);
public:
    RGBTriangle(GLdouble r);
    void update() override;
};

