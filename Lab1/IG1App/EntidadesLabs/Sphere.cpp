#include "Sphere.h"
#include "../IndexMesh.h"
#include "glm/gtc/type_ptr.hpp"

Sphere::Sphere(GLdouble r, GLuint nParallels, GLuint nMeridians, glm::vec4 col)
	: ColorMaterialEntity(col) // Por el enunciado supongo que siempre será verde?
{
	std::vector<glm::vec2> vProfile(nParallels+1);

	const float angleDelta = glm::radians(180.f / (float)nParallels);
	constexpr float offSet = glm::radians(90.f);
	// Creamos los vertices
	for (int i = 0; i < nParallels; i++)
	{
		float angle = offSet + angleDelta * i;
		vProfile[i] = { r * glm::cos(angle), r * glm::sin(angle) };
	}

	vProfile[nParallels] = { 0, -r};

	mMesh = IndexMesh::generateByRevolution(vProfile, nMeridians);
}
