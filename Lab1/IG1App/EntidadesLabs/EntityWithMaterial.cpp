#include "EntityWithMaterial.h"

EntityWithMaterial::EntityWithMaterial() {
	mShader = Shader::get("light");
}

void EntityWithMaterial::render(const glm::mat4& modelViewMat) const
{
	mShader->use();
	// Carga los atributos del material en la GPU
	mMaterial.upload(*mShader);
	upload(modelViewMat * mModelMat);
	mMesh->render();

	if (mMesh != nullptr && sShowNormals)
	{
		glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		Shader* debugShader = Shader::get("normals");
		debugShader->use();
		debugShader->setUniform("modelView", aMat);
		mMesh->render();
	}
}

void EntityWithMaterial::toggleShowNormals()
{
	sShowNormals = !sShowNormals;
}
