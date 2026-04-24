#include "Scene8.h"

#include "../EntidadesLabs/Sphere.h"
#include "../EntidadesLabs/Droid.h"
#include "../EntidadesLabs/CompoundEntity.h"
#include "glm/gtc/matrix_transform.hpp"
#include "../Light.h"

void Scene8::init()
{
	Scene::init();

	// Create planet
	GLdouble planetRadius = 150;
	Sphere* planet = new Sphere(planetRadius, 12, 12, { 0.67, 0.129, 0.28, 1 });
	gObjects.push_back(planet);

	// Create droid
	GLdouble droidRadius = planetRadius / 10;
	mDroid = new Droid(droidRadius);

	// Compound entity for easier rotations
	mOrbitNode = new CompoundEntity;
	mOrbitNode->setModelMat(glm::translate(glm::mat4(1), { 0, planetRadius + droidRadius, 0 }));

	// Add droid to orbit node
	mOrbitNode->addEntity(mDroid);

	gObjects.push_back(mOrbitNode);

	// Lights
	PosLight* spotLightT = new PosLight(0);
	spotLightT->setPosition({ 0, planetRadius * 1.5, 0 });
	
	spotLightT->setAmb({ 0.25, 0.25, 0.25 });
	spotLightT->setDiff({ 0.6, 0.6, 0.6 });
	spotLightT->setSpec({ 0.0, 0.2, 0.0 });

	gLights.push_back(spotLightT);

	// TODO: Los bordes se ven difuminados
	SpotLight* spotLightY = new SpotLight({ 0, 0, planetRadius * 1.1 }, 0);
	
	spotLightY->setAmb({ 0.25, 0.25, 0.25 });
	spotLightY->setDiff({ 0.6, 0.6, 0.6 });
	spotLightY->setSpec({ 0.0, 0.2, 0.0 });

	gLights.push_back(spotLightY);
}

void Scene8::rotate()
{
	mDroid->setModelMat(glm::rotate(glm::mat4(1), glm::radians(5.f), { 0,1,0 }) * mDroid->modelMat());
}

void Scene8::orbit()
{
	// Hay que pillar la rotacion global del droide para que no se desincronice al rotarlo y orbitarlo muchas veces
	glm::mat4 worldMat = mOrbitNode->modelMat() * mDroid->modelMat();
	glm::vec3 lookDir = glm::normalize(glm::vec3(worldMat[0]));

	// Aplicamos una rotacion en el sentido en el que mira el robot
	glm::mat4 rotation = glm::rotate(glm::mat4(1), glm::radians(5.f), lookDir);
	mOrbitNode->setModelMat(rotation * mOrbitNode->modelMat());
}

void Scene8::setGL()
{
	glClearColor(0.0, 0.0, 0.0, 1.0); // background color (alpha=1 -> opaque)
	glEnable(GL_DEPTH_TEST);          // enable Depth test
}
