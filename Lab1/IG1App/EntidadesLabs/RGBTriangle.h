#ifndef _H_RGBTriangle_H_
#define _H_RGBTriangle_H_

#include "../Entity.h"

class RGBTriangle :
    public EntityWithColors
{
private:
    /*float m_fOrbitAngle = 0;
    float m_fOrbitRad = glm::sqrt(10000 * 2);
    float m_fSpinAngle = 0;*/
public:
    RGBTriangle(GLdouble r);
    void update() override;
};

#endif