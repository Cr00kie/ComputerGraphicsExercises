#include "Disk.h"
#include "../IndexMesh.h"
#include "glm/gtc/type_ptr.hpp"

Disk::Disk(GLdouble R, GLdouble r, GLuint nRings, GLuint nSamples, glm::vec4 col)
	: ColorMaterialEntity(col) // Por el enunciado supongo que siempre será verde?
{
	std::vector<glm::vec2> vProfile(nRings+1);

	float stepX = (R - r) / nRings;
	float ringX = r;
	for (int i = 0; i <= nRings; ++i)
	{
		vProfile[i] = { ringX, 0 };
		ringX += stepX;
	}

	mMesh = IndexMesh::generateByRevolution(vProfile, nSamples);
}
