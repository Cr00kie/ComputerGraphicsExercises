#include "Sphere.h"
#include "../IndexMesh.h"
#include "glm/gtc/type_ptr.hpp"

Sphere::Sphere(GLdouble r, GLuint nParallels, GLuint nMeridians, glm::vec4 col)
	: ColorMaterialEntity(col) // Por el enunciado supongo que siempre será verde?
{
	mMesh = IndexMesh::generateSphere(r, nParallels, nMeridians);
}
