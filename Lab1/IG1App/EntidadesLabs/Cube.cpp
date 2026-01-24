#include "Cube.h"

Cube::Cube(GLdouble length, glm::vec4 col)
	: SingleColorEntity(col)
{
	mMesh = Mesh::generateCube(length);
}

void Cube::render(const glm::mat4& modelViewMat) const
{
	if (mMesh != nullptr) {
		glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		mShader->use();
		upload(aMat);

		glEnable(GL_CULL_FACE); // Activa el renderizado solo para las caras visibles para la cámara

		glCullFace(GL_FRONT); // También se puede hacer: glFrontFace(GL_CCW); 
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		mMesh->render();

		glCullFace(GL_BACK); // También se puede hacer: glFrontFace(GL_CW); 
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		mMesh->render();

		glDisable(GL_CULL_FACE);
	}
}
