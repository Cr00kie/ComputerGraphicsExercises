#include "Star3D.h"
#include "glm/gtc/matrix_transform.hpp"

Star3D::Star3D(GLdouble re, GLuint np, GLdouble h, const std::string& imgPath) : EntityWithTexture(imgPath)
{
	mMesh = Mesh::generateStar3DTexCor(re, np, h);
}

void Star3D::render(const glm::mat4& modelViewMat) const
{
	if (mMesh != nullptr) {
		glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		mShader->use();
		upload(aMat);
		mShader->setUniform("modulate", mModulate);

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		mTexture->bind();
		mMesh->render();

		aMat = glm::rotate(aMat, glm::radians(180.f), glm::vec3(0,1,0));
		upload(aMat);
		mMesh->render();
		mTexture->unbind();
	}
}

void Star3D::update()
{
	rotationY += rotSpeedY;
	rotationZ += rotSpeedZ;

	glm::mat4 T = glm::mat4(1);

	T = glm::translate(T, glm::vec3(mModelMat[3][0], mModelMat[3][1], mModelMat[3][2]));
	T = glm::rotate(T, glm::radians(rotationY), glm::vec3(0.0, 1.0, 0.0));
	T = glm::rotate(T, glm::radians(rotationZ), glm::vec3(0.0, 0.0, 1.0));

	setModelMat(T);
}
