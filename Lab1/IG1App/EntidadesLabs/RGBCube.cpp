#include "RGBCube.h"

#include "glm/gtc/matrix_transform.hpp"
#include <iostream>

RGBCube::RGBCube(GLdouble length) : m_dHalfLength(length/2)
{
	mMesh = Mesh::generateRGBCubeTriangles(length);
	m_Pivot = { 0, -m_dHalfLength, m_dHalfLength };
}

void RGBCube::render(const glm::mat4& modelViewMat) const
{
	if (mMesh != nullptr) {
		glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		mShader->use();
		upload(aMat);

		glEnable(GL_CULL_FACE); // Activa el renderizado solo para las caras visibles para la cámara

		glCullFace(GL_BACK); // También se puede hacer: glFrontFace(GL_CCW); 
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		mMesh->render();

		glDisable(GL_CULL_FACE);
	}
}

void RGBCube::update()
{
	if (m_fCurrRotation > glm::pi<float>())
	{
		m_fCurrRotation = 0;
		switch (m_CurrentAxe)
		{
		case Axes::X:
			m_CurrentAxe = Axes::Z;
			m_Pivot = { -m_dHalfLength, -m_dHalfLength, 0 };
			m_fRotationSpeed *= -1;
			break;
		case Axes::Y:
			m_Pivot = { 0, -m_dHalfLength, m_dHalfLength };
			m_CurrentAxe = Axes::X;
			break;
		case Axes::Z:
			m_Pivot = { -m_dHalfLength, 0, m_dHalfLength };
			m_CurrentAxe = Axes::Y;
			m_fRotationSpeed *= -1;
			break;
		}
	}

	m_fCurrRotation += glm::abs(m_fRotationSpeed);

	glm::mat4 model = modelMat();
	glm::vec3 rotationAxe(0,0,0);
	rotationAxe[m_CurrentAxe] = 1;
	
	model = glm::translate(model, m_Pivot);
	model = glm::rotate(model, m_fRotationSpeed, rotationAxe);
	model = glm::translate(model, -m_Pivot);

	setModelMat(model);
}
