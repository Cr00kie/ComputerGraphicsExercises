#include "Torus.h"
#include "../IndexMesh.h"
#include "glm/gtc/type_ptr.hpp"

Torus::Torus(GLdouble R, GLdouble r, GLuint nPoints, GLuint nSamples, glm::vec4 col)
	: ColorMaterialEntity(col) // Por el enunciado supongo que siempre será verde?
{
	std::vector<glm::vec2> vProfile(nPoints+1);

	// TODO: Esto no funca. Si miras el Torus por debajo se ve que hay algo mal
	const float angleDelta = glm::radians(360.0f / (float)nPoints);
	constexpr float offSet = glm::radians(-90.f);
	// Creamos los vertices
	for (int i = 0; i < nPoints; i++)
	{
		float angle = offSet + angleDelta * i;
		vProfile[i] = { R + r * glm::cos(angle), r * glm::sin(angle) };
	}

	// Cerramos el círculo
	vProfile[nPoints] = vProfile[0];

	mMesh = IndexMesh::generateByRevolution(vProfile, nSamples);
}
