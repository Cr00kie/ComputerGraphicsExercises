#include "GlassParapet.h"

GlassParapet::GlassParapet(GLdouble length, const std::string& imgName, GLubyte alpha)
	: EntityWithTexture(imgName, alpha)
{
	mMesh = Mesh::generateBoxOutlineTexCor(length);
}
