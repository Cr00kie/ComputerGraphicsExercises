#include "Scene8.h"

#include "../EntidadesLabs/Sphere.h"

void Scene8::init()
{
	Scene::init();

	Sphere* sphere = new Sphere(50, 12, 12, { 0.67, 0.129, 0.28, 1 });
	gObjects.push_back(sphere);
}

void Scene8::setGL()
{
	glClearColor(0.0, 0.0, 0.0, 1.0); // background color (alpha=1 -> opaque)
	glEnable(GL_DEPTH_TEST);          // enable Depth test
}
