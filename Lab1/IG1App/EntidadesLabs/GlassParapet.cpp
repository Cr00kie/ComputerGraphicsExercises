#include "GlassParapet.h"

GlassParapet::GlassParapet(GLdouble length, const std::string& imgName, GLubyte alpha)
	: EntityWithTexture(imgName, alpha)
{
	mMesh = Mesh::generateBoxOutline(length);
}

void GlassParapet::render(const glm::mat4& modelViewMat) const
{
	if (mMesh) {
		glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		mShader->use();

		// Ponemos el uniform modulate
		mShader->setUniform("modulate", mModulate);
		upload(aMat);

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		// Si la textura no es nula renderizamos la malla con la textura
		if (mTexture)
		{
			mTexture->bind();
			mMesh->render();
			mTexture->unbind();
		}
	}
}
