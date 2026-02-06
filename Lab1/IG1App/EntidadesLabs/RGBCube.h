#pragma once
#include "../Entity.h"



class RGBCube :
    public EntityWithColors
{
public:
    RGBCube(GLdouble length);
    void render(const glm::mat4& modelViewMat) const override;
    void update() override;
private:
    enum Axes
    {
        X,
        Y,
        Z
    };

    float m_fCurrRotation = 0;
    float m_fRotationSpeed = glm::radians(0.2f);
    Axes m_CurrentAxe = Axes::X;
    glm::vec3 m_Pivot;
    GLdouble m_dHalfLength;
};

