#ifndef _H_Ground_H_
#define _H_Ground_H_


#include "EntityWithTexture.h"

class Ground :
    public EntityWithTexture
{
public:
    Ground(GLdouble length, const std::string& imageName);
    void render(const glm::mat4& modelViewMat) const override;
};

#endif