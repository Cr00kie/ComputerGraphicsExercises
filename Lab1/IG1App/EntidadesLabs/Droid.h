#ifndef _H_Droid_H_
#define _H_Droid_H_
#include "CompoundEntity.h"

class SpotLight;

class Droid : public CompoundEntity
{
public:
	Droid(GLdouble bodyRadius);
	void render(const glm::mat4& modelViewMat) const override;

private:
	SpotLight* spotLight;
};

#endif