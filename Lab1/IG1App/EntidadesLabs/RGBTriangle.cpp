#include "RGBTriangle.h"
#include "glm/gtc/matrix_transform.hpp"
#include <iostream>

RGBTriangle::RGBTriangle(GLdouble r)
{
	mMesh = Mesh::generateRBGTriangle(r);
}

void RGBTriangle::update()
{
	constexpr float rotateSpeed = glm::radians(-0.05f);
	glm::mat4 mat = modelMat();

	// Rotamos mat sobre si mismo
	mat = glm::rotate(modelMat(), rotateSpeed, { 0,0,1 });

	// Rotamos mat sobre un pivote
	//									/-- Hay que multiplicar por dos, lo he sacado probando
	glm::vec3 pos = { glm::sqrt(10000 * 2) * 2, 0, 0 };
	mat = glm::translate(mat, -pos);
	mat = glm::rotate(mat, rotateSpeed, { 0,0,1 });
	mat = glm::translate(mat, pos);

	// Actualizamos mat
	setModelMat(mat);
	
}
