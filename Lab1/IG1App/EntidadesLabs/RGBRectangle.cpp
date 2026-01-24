#include "RGBRectangle.h"

RGBRectangle::RGBRectangle(GLdouble w, GLdouble h)
{
	mMesh = Mesh::generateRGBRectangle(w, h);
}

void RGBRectangle::render(const glm::mat4& modelViewMat) const
{
	if (mMesh) {
		glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		mShader->use();
		upload(aMat);
		
		glEnable(GL_CULL_FACE);

		glCullFace(GL_BACK); // ? PORQUE FUNCIONA AL REVES NO ENTIENDO (SI PONES FRONT, EL FRONT SE PONE CON FILL)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		mMesh->render();

		glCullFace(GL_FRONT);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		mMesh->render();

		glDisable(GL_CULL_FACE);
	}
}
