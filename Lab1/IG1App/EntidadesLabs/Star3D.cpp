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
