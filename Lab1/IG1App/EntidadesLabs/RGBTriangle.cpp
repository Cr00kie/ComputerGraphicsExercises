#include "RGBTriangle.h"
#include "glm/gtc/matrix_transform.hpp"
#include <iostream>

RGBTriangle::RGBTriangle(GLdouble r)
{
	mMesh = Mesh::generateRBGTriangle(r);
}

void RGBTriangle::update()
{
	constexpr float spinSpeed = glm::radians(-0.8f);
	constexpr float orbitSpeed = glm::radians(0.3f);

	glm::mat4 mat = glm::mat4(1.f);

	// Aplicamos la orbita alrededor del circulo
	mat = glm::translate(mat, { glm::cos(m_fOrbitAngle) * m_fOrbitRad, 
								glm::sin(m_fOrbitAngle) * m_fOrbitRad, 
								0 });
	// Rotamos mat sobre si mismo
	mat = glm::rotate(mat, m_fSpinAngle, {0,0,1});

	m_fOrbitAngle += orbitSpeed;
	m_fSpinAngle += spinSpeed;

	// Actualizamos mat
	setModelMat(mat);
	
}
