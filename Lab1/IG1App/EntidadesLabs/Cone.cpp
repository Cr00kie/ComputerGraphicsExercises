#include "Cone.h"
#include "../IndexMesh.h"
#include "glm/gtc/type_ptr.hpp"

Cone::Cone(GLdouble h, GLdouble r, GLdouble R, GLuint nRings, GLuint nSamples, glm::vec4 col)
	: ColorMaterialEntity(col) // Por el enunciado supongo que siempre será verde?
{
	std::vector<glm::vec2> vProfile(nRings+1);

	float stepY = h / nRings;
	float stepX = (r - R) / nRings;

	float ringX = R;
	float ringY = h / 2;
	for (int i = 0; i <= nRings; i++)
	{
		vProfile[i] = { ringX, ringY };

		ringX += stepX;
		ringY -= stepY;
	}

	mMesh = IndexMesh::generateByRevolution(vProfile, nSamples);
}
