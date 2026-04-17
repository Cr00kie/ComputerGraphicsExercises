#include "SphereWithTexture.h"

#include "../IndexMesh.h"

SphereWithTexture::SphereWithTexture(GLdouble r, GLuint nParallels, GLuint nMeridians, const std::string& imageName, GLfloat alpha)
	: EntityWithTexture(imageName, alpha)
{
	mMesh = IndexMesh::generateSphere(r, nParallels, nMeridians);
}
