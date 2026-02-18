#include "EntityWithTexture.h"

EntityWithTexture::EntityWithTexture()
{
	// Cogemos shader que usa texturas
	mShader = Shader::get("texture");
}

void EntityWithTexture::render(const glm::mat4& modelViewMat) const
{
	if (mMesh != nullptr)
	{
		glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		mShader->use();
		// Ponemos el uniform modulate
		mShader->setUniform("modulate", mModulate);
		upload(aMat);
		// Si la textura no es nula renderizamos la malla con la textura
		if (mTexture)
		{
			mTexture->bind();
			mMesh->render();
			mTexture->unbind();
		}
	}
}
