#include "Grass.h"
#include "glm/gtc/matrix_transform.hpp"

Grass::Grass(GLdouble w, GLdouble h, const std::string& imgName, GLubyte alpha)
	: EntityWithTexture(imgName, alpha)
{
	mMesh = Mesh::generateRectangleTexCor(w, h, 1, 1);
	mShader = Shader::get("texture:texture_alpha");
}

void Grass::render(const glm::mat4& modelViewMat) const
{
	if (mMesh != nullptr)
	{
		glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		mShader->use();
		// Ponemos el uniform modulate
		mShader->setUniform("modulate", mModulate);
		// Si la textura no es nula renderizamos la malla con la textura
		if (mTexture)
		{
			mTexture->bind();
			
			upload(aMat);
			mMesh->render();

			aMat = glm::rotate(aMat, glm::radians(120.f), glm::vec3(0, 1, 0));
			upload(aMat);
			mMesh->render();

			aMat = glm::rotate(aMat, glm::radians(120.f), glm::vec3(0, 1, 0));
			upload(aMat);
			mMesh->render();


			mTexture->unbind();
		}
	}
}
