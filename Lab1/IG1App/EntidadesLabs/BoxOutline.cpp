#include "BoxOutline.h"
#include "../Scene.h"

BoxOutline::BoxOutline(GLdouble length, const std::string& innerImageName, const std::string& outerImageName)
	: EntityWithTexture(outerImageName), mInnerTexture(Scene::getTexture(innerImageName))
{
	mMesh = Mesh::generateBoxOutline(length);
}

void BoxOutline::render(const glm::mat4& modelViewMat) const
{
	if (mMesh) {
		glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		mShader->use();

		// Ponemos el uniform modulate
		mShader->setUniform("modulate", mModulate);
		upload(aMat);

		glEnable(GL_CULL_FACE);

		glCullFace(GL_BACK);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		// Si la textura no es nula renderizamos la malla con la textura
		if (mTexture)
		{
			mTexture->bind();
			mMesh->render();
			mTexture->unbind();
		}

		glCullFace(GL_FRONT);

		// Si la textura no es nula renderizamos la malla con la textura
		if (mInnerTexture)
		{
			mInnerTexture->bind();
			mMesh->render();
			mInnerTexture->unbind();
		}

		glDisable(GL_CULL_FACE);
	}
}
