#ifndef _H_BoxOutline_H_
#define _H_BoxOutline_H_

#include "EntityWithTexture.h"

class BoxOutline :
    public EntityWithTexture
{
public:

    BoxOutline(GLdouble length, const std::string& innerImageName, const std::string& outerImageName);
	void render(const glm::mat4& modelViewMat) const override;

private:
	Texture* mInnerTexture = nullptr;
};

#endif