#include "ColorMaterialEntity.h"

bool ColorMaterialEntity::sShowNormals = false;

ColorMaterialEntity::ColorMaterialEntity(glm::vec4 col)
	: SingleColorEntity(col)
{
	mShader = Shader::get("simple_light");
}

void ColorMaterialEntity::toggleShowNormals()
{
	sShowNormals = !sShowNormals;
}

void ColorMaterialEntity::render(const glm::mat4& modelViewMat) const
{
	SingleColorEntity::render(modelViewMat);

	if (mMesh != nullptr && sShowNormals)
	{
		glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		Shader* debugShader = Shader::get("normals");
		debugShader->use();
		debugShader->setUniform("modelView", aMat);
		mMesh->render();
	}
}
