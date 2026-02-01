#include "RGBTriangle.h"
#include "glm/gtc/matrix_transform.hpp"
#include <iostream>

RGBTriangle::RGBTriangle(GLdouble r)
{
	mMesh = Mesh::generateRBGTriangle(r);
}

void RGBTriangle::update()
{
	constexpr float spinSpeed = glm::radians(-0.2f);
	constexpr float orbitSpeed = glm::radians(0.5f);
	glm::mat4 mat = modelMat();

	// Ponemos la matriz en el (0,0,0)
	mat[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	// Rotamos mat sobre si mismo
	mat = glm::rotate(mat, spinSpeed, { 0,0,1 });

	// Aplicamos la orbita al rededor del circulo
	mat = glm::translate(mat, { glm::cos(m_fOrbitAngle) * m_fOrbitRad, 
								glm::sin(m_fOrbitAngle) * m_fOrbitRad, 
								0 });
	m_fOrbitAngle += orbitSpeed;
	std::cout << "Angle: " << m_fOrbitAngle << '\n';

	// Actualizamos mat
	setModelMat(mat);
	
}
