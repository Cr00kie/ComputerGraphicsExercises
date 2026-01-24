#include "SingleColorEntity.h"

SingleColorEntity::SingleColorEntity(glm::vec4 color)
	: mColor(color), Abs_Entity()
{
	mShader = Shader::get("simple");
}

void SingleColorEntity::render(const glm::mat4& modelViewMat) const
{
	if (mMesh != nullptr) {
		glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		mShader->use();
		upload(aMat);
		mShader->setUniform("color", mColor);
		mMesh->render();
	}
}
