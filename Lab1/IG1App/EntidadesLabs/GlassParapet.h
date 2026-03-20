#ifndef _H_GlassParapet_H_
#define _H_GlassParaper_H_


#include "EntityWithTexture.h"
class GlassParapet : public EntityWithTexture
{
public:
	GlassParapet(GLdouble length, const std::string& imgName, GLubyte alpha);
};

#endif