#include "Ground.h"

#include "glm/gtc/matrix_transform.hpp"

Ground::Ground(GLdouble length, const std::string& imageName)
	: EntityWithTexture(imageName)
{
	mMesh = Mesh::generateRectangleTexCor(length, length, 4, 4);
	setModelMat(glm::rotate(glm::mat4(1.f), glm::radians(-90.f), glm::vec3(1, 0, 0)));
}

void Ground::render(const glm::mat4& modelViewMat) const
{
	EntityWithTexture::render(modelViewMat);
}
