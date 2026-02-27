#pragma once
#include "EntityWithTexture.h"
class GlassParapet : public EntityWithTexture
{
public:
	GlassParapet(GLdouble length, const std::string& imgName, GLubyte alpha);

	void render(const glm::mat4& modelViewMat) const override;
};

