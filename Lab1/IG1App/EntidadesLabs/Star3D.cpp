#include "Star3D.h"
#include "glm/gtc/matrix_transform.hpp"

Star3D::Star3D(GLdouble re, GLuint np, GLdouble h, glm::vec4 color) : SingleColorEntity(color)
{
	mMesh = Mesh::generateStar3D(re, np, h);
}

void Star3D::render(const glm::mat4& modelViewMat) const
{
	if (mMesh != nullptr) {
		glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		mShader->use();
		upload(aMat);
		mShader->setUniform("color", mColor);

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		mMesh->render();

		aMat = glm::rotate(aMat, glm::radians(180.f), glm::vec3(1,0,0));
		upload(aMat);
		mMesh->render();
	}
}

void Star3D::update()
{
	glm::mat4 rotZ = glm::rotate(modelMat(), glm::radians(rotationZ), glm::vec3(0, 0, 1));
	glm::mat4 rotY = glm::rotate(glm::mat4(1), glm::radians(rotationY), glm::vec3(0, 1, 0));

	setModelMat(rotY * rotZ);
}
