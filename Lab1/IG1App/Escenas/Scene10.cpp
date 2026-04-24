#include "Scene10.h"

#include "../EntidadesLabs/Sphere.h"
#include "glm/gtc/matrix_transform.hpp"

void Scene10::init()
{
	Scene::init();

	GLdouble sphereRadius = 50;

	Sphere* sphere1 = new Sphere(sphereRadius, 12, 12, { 1.0, 1.0, 0.0, 1 });
	gObjects.push_back(sphere1);

	sphere1->setModelMat(glm::translate(glm::mat4(1), glm::vec3(0, 0, 2 * sphereRadius)));

	Sphere* sphere2 = new Sphere(sphereRadius, 12, 12, { 1.0, 1.0, 0.0, 1 });
	gObjects.push_back(sphere2);

	sphere2->setModelMat(glm::translate(glm::mat4(1), glm::vec3(2 * sphereRadius, 0, 0)));

	Material m;
	m.setGolden();
	sphere1->setMaterial(m);
	

	// TODO: Poner la esfera 2 dorada
}
